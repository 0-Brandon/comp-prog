#include <bits/stdc++.h>
#define int long long
using namespace std;
//1 2 3 4 5 6
int t, te;
void solve(){
    int n, k;cin>>n>>k;
    if(k&1||(k>(n-1+(n+1)%2)*((n+1)/2))){cout<<"NO\n";return;}
    vector<int> ans(n);
    iota(ans.begin(),ans.end(),1);
    int lim = (n-1)*2;
    for(int i=0; i<n;i++,lim-=4){
        if(k<=lim){
            swap(ans[i+k/2],ans[i]);
            break;
        }
        k-=lim;
        swap(ans[i+lim/2],ans[i]);
    }
    cout<<"YES\n";
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;te=t;
    while(t--){
        solve();
    }
}