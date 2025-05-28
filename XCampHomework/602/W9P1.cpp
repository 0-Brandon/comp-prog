#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int LOG = 19;
signed main(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    vector<int> s(n);
    iota(s.begin(),s.end(),0);
    int ans = 0;
    auto work = [&](auto&& work, vector<int>::iterator l, vector<int>::iterator r, int bi){    
        if(l==r)return;
        if(bi<0){
            for(int j=LOG; j>=0; j--){
                vector<int> cnt(2,0);
                for(auto it = l; it!=r; it++){
                    int i = *it;
                    cnt[a[i]>>j&1]++;
                }
                ans+=cnt[0]*cnt[1]*(1<<j);
            }
            return;
        }
        auto mid=partition(l,r,[&](int i){return (a[i]>>bi&1)==0&&(b[i]>>bi&1)==0||(a[i]>>bi&1)==1&&(b[i]>>bi&1)==1;});
        //if element is 00 
        //we go down, adding a[i]
        vector cnt(2,vector (2, vector (2, vector<int>(LOG+1,0))));
        for(auto it = mid; it!=r; it++){
            int i = *it;
            int g = ((a[i]>>bi&1));
            for(int j=LOG; j>=0; j--){
                cnt[g][0][a[i]>>j&1][j]++;
                cnt[g][1][b[i]>>j&1][j]++;
            }
        }
        for(auto it = l;it!=mid; it++){
            int i = *it;
            if((a[i]>>bi&1)==0&&(b[i]>>bi&1)==0){
                //00
                //add 01 a vals
                //add 10 b vals
                //group array value [j]
                for(int j=LOG; j>=0; j--){
                    ans+=cnt[0][0][!(a[i]>>j&1)][j]*(1<<j);
                    ans+=cnt[1][1][!(b[i]>>j&1)][j]*(1<<j);
                }
            }else{
                //11
                //add 10 a vals
                //add 01 b vals
                for(int j=LOG; j>=0; j--){
                    ans+=cnt[0][1][!(b[i]>>j&1)][j]*(1<<j);
                    ans+=cnt[1][0][!(a[i]>>j&1)][j]*(1<<j);
                }
            }
        }
        work(work,l,mid,bi-1);
        work(work, mid, r,bi-1);
    };
    work(work, s.begin(),s.end(), LOG);
    cout<<ans<<"\n";
}