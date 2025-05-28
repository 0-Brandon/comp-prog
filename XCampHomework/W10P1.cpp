#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    constexpr int b = 400;
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    vector<vector<int>> blx(b);
    for(int i=0;i<n; i++){
        cin>>a[i];
        blx[i/b].push_back(a[i]);
    }
    for(auto& i:blx){
        sort(i.begin(),i.end());
    }
    for(int i=0; i<q; i++){
        char t;cin>>t;
        if(t=='M'){
            int i, x;cin>>i>>x;
            i--;
            auto id = i/b;
            blx[id].erase(lower_bound(blx[id].begin(),blx[id].end(),a[i]));
            a[i]=x;
            blx[id].insert(lower_bound(blx[id].begin(),blx[id].end(),a[i]),a[i]);
        }
        else{
            int l, r,x;cin>>l>>r>>x;l--,r--;
            int ans = 0;
            for(int i=l; i<=r; i++){
                for(;i%b==0&&i+b<=r;i+=b){
                    ans+=upper_bound(blx[i/b].begin(),blx[i/b].end(),x)-blx[i/b].begin();
                }
                ans+=(a[i]<=x);
            }
            cout<<ans<<"\n";
        }
    }
}