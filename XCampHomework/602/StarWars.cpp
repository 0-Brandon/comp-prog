#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    cin.tie(0)->sync_with_stdio(false);
    int  n, m;
    cin>>n>>m;
    vector<int> in(n), rem(n);
    vector<int> h(n);
    int tot = 0;
    for(int i=0; i<n; i++)h[i] = rng(),tot+=h[i];
    int cur = 0;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        in[b]+=h[a];
        rem[b] = in[b];
        cur+=h[a];
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int a, b;cin>>a>>b;a--,b--;
            in[b]-=h[a];
            cur-=h[a];
        }
        else if(t==2){
            int b;cin>>b;b--;
            cur-=in[b];
            in[b] = 0;
        }
        else if(t==3){
            int a, b;cin>>a>>b;a--,b--;
            in[b]+=h[a];
            cur+=h[a];
        }
        else{
            int b;cin>>b;b--;
            cur+=rem[b]-in[b];
            in[b]=rem[b];
        }
        //if this is true, we assume each h[i] is somewhere once and only once
        if(cur==tot)cout<<"YES\n";
        else cout<<"NO\n";
    }
}