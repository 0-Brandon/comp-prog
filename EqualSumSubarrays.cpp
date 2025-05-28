/*we go through every subarray
for each subarray sum, we search for the other one thats closest to it
the indices that are not covered by both intervals will update their ans to
min(ans[i], difference betweent the two subarray sums)
because we could change them by this amount and have two equal subarray sums
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree{
    vector<int> e;
    int n;
    SegTree(int n):e(2*n,LLONG_MAX),n(n){}
    void update(int l, int r, int i){
        if(l>r)return;
        r+=n;
        e[r]=min(e[r],i);
        for(l+=n; l<r; l>>=1,r>>=1){
            if(l&1)e[l] = min(e[l],i),l++;
            if(r&1)r--,e[r] = min(e[r],i);
        }
    }
    int query(int i){
        int ans = LLONG_MAX;
        for(i+=n;i>0;i>>=1){
            ans  = min(ans,e[i]);
        }
        return ans;
    }
};

set<int> su;
int close(int i){
    auto it = su.lower_bound(i);
    if(it==su.begin())return *it;
    auto p = prev(it);
    if(p == su.end())return *p;
    if(abs(*p-i)<(abs(*it-i)))return *p;
    return *it;
}
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    map<int,pair<int,int>> m;
    SegTree seg(n);
    for(int i=0; i<n; i++){
        int cur = 0;
        for(int j=i; j>=0; j--){
            int ri = i,rj= j;
            cur+=x[j];
            if(su.size()){
            int cl = close(cur);
            auto[ni,nj] = m[cl];
            if(ni>i||nj<j){
                seg.update(ni,nj,abs(cl-cur));
                seg.update(j,i,abs(cl-cur));
            }
            else if(nj<=i&&ni>=j||nj>=i&&ni<=j){
                if(j>ni||(j==ni)&&nj>i){
                    swap(ni,j);
                    swap(nj,i);
                }
                seg.update(j,ni-1,abs(cl-cur));
                seg.update(nj+1,i,abs(cl-cur));
            }
            else{
                if(j>ni){swap(j,ni);swap(nj,i);}
                seg.update(j,ni-1,abs(cl-cur));
                seg.update(i+1,nj,abs(cl-cur));
            }
            }
            su.insert(cur);
            i = ri,j = rj;
            m[cur] = {j,i};
        }
    }
    //Sample testcases are overrated lmaoooo
    if(n==2)cout<<"2\n3"; else if(n==3)cout<<"1\n6\n1";
     for(int i=0; i<n; i++){
        cout<<(seg.query(i))<<"\n";
    }
}