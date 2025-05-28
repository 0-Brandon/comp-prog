#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Segtree{
    vector<int> e, ans;
    Segtree(int n):e(4*n,0),ans(4*n,0){}
    int query(){
        return ans[0];
    }
    void update(int id, int dl, int dh, int l, int h, int a){
        if(dl>h||dh<l)return;
        if(l<=dl&&h>=dh){
            e[id]+=a;
            if(dl==dh)ans[id] = (e[id]>0)?1:0;
            else ans[id] = (e[id]>0)?(dh-dl+1):(ans[id*2+1]+ans[id*2+2]);
            return;
        }
        int mid = (dl+dh)/2;
        update(id*2+1,dl,mid,l,h,a);
        update(id*2+2,mid+1,dh,l,h,a);
        ans[id] = (e[id]>0)?(dh-dl+1):(ans[id*2+1]+ans[id*2+2]);
    }
};
signed main(){
    int n;
    cin>>n;
    vector<vector<array<int,3>>> time(2e6+5);
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(y1>y2)swap(y1,y2);
        if(x1>x2)swap(x1,x2);
        time[x1+1e6].push_back({y1+1e6,y2+1e6-1,1});
        time[x2+1e6].push_back({y1+1e6,y2+1e6-1,-1});
    }
    Segtree seg(2e6+5);
    int ans = 0;
    for(int i=0; i<2e6+5; i++){
        ans+=seg.query();
        for(auto& j:time[i]){
            seg.update(0,0,2e6+5-1,j[0],j[1],j[2]);
        }
    }
    cout<<ans<<"\n";
}