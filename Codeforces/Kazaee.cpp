#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

struct Segtree{
    int n;
    vector<int> e;
    Segtree(int a):n(a),e(2*n){}
    void upd(int i, int u){
        for(e[i+=n]=u; i>>=1;){
            e[i] = e[i<<1]+e[i<<1|1];
        }
    }
    int query(int l, int r){
        int ans = 0;
        for(ans = e[r+=n],l+=n; l<r; l/=2,r/=2){
            if(l&1)ans+=e[l++];
            if(r&1)ans+=e[--r];
        }
        return ans;
    }
};
constexpr int LOG = 26;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, q;cin>>n>>q;
    map<int,long long> mp;
    vector<Segtree> segs(LOG+1, Segtree(n));
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(mp[x[i]]==0)mp[x[i]] = rng();
        for(int j=LOG; j>=0; j--){
            segs[j].upd(i,(mp[x[i]]>>j)&1);
        }
    }
    while(q--){
        int t;cin>>t;
        if(t==1){
            int i, a;
            cin>>i>>a;i--;
            x[i] = a;
            if(mp[x[i]]==0)mp[x[i]] = rng();
            for(int j=LOG; j>=0; j--){
                segs[j].upd(i,(mp[x[i]]>>j)&1);
            }
        }else{
            int l, r, k;cin>>l>>r>>k;l--,r--;
            bool b = false;
            for(int j=0; j<=LOG; j++){
                if(segs[j].query(l,r)%k!=0){
                    cout<<"NO\n"; b= true; break;
                }
            }
            if(!b)cout<<"YES\n";
        }
    }
}