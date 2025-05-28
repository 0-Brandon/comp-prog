#include <bits/stdc++.h>
#define int long long
using namespace std;

struct info{
    array<int,4> e;
    info operator+(info& o){
        info c;
        c.e[0] = min(e[0],o.e[0]);
        c.e[3] = max(e[3],o.e[3]);
        //smallest pos
        if(o.e[1]>=0&&e[1]<0)c.e[1] = o.e[1];
        else if(e[1]>=0&&o.e[1]<0)c.e[1]=e[1];
        else c.e[1] = min(o.e[1],e[1]); //what if they're both negative??
        
        if(o.e[2]>0&&e[2]<=0)c.e[2] = e[2];
        else if(e[2]>0&&o.e[2]<=0)c.e[2]=o.e[2];
        else c.e[2] = max(o.e[2],e[2]); //what if they're both pos??
        return c;
    }
};
struct Segtree{
    int n;
    vector<info> e;
    Segtree(vector<int>& a):n(a.size()),e(2*n){
        for(int i=0; i<a.size(); i++){
            e[i+n] = {a[i],a[i],a[i],a[i]}; //check if this initialization actually works
        }
        for(int i=n-1; i>0; i--)e[i] = e[i*2]+e[i*2+1];
    }
    info query(int l, int r){
        info ans;
        for(l+=n,ans = e[r+=n]; l<r; l/=2,r/=2){
            if(l&1)ans = ans+e[l++];
            if(r&1)ans=ans+e[--r];
        }
        return ans;
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> a(n),b(m);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    Segtree sa(a),sb(b);
    while(q--){
        int l, r, ans=-2e18;cin>>l>>r;l--,r--;
        info ia = sa.query(l,r);
        cin>>l>>r;l--,r--;
        info ib = sb.query(l,r);
        for(auto& i:ia.e){
            int cur = 2e18;
            for(auto& j:ib.e){
                cur=min(cur,i*j);
            }
            ans = max(ans,cur);
        }
        cout<<ans<<"\n";
    }
}