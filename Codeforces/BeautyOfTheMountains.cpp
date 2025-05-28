#include <bits/stdc++.h>
#define int long long
using namespace std;
int inf = 1e17;
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> h(n, vector<int>(m)), t(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>h[i][j];
        }
    }
    int su =0;
    vector<vector<int>> pref(n+1, vector<int>(m+1));
    for(int i=0; i<n; i++){
        string s;cin>>s;
        for(int j=0; j<m; j++){
            t[i][j]=(s[j]=='0');
            if(t[i][j])su+=h[i][j];
            else su-=h[i][j];
            pref[i+1][j+1] = pref[i+1][j]+pref[i][j+1]-pref[i][j]+(t[i][j]?1:-1);
        }
    }
    for(auto& i:pref){
       // for(auto& j:i)cout<<j<<" ";cout<<"\n";
    }
    int g = 0;
    for(int i=k; i<=n; i++){
        for(int j=k; j<=m; j++){
            int sq = pref[i][j]-pref[i-k][j]-pref[i][j-k]+pref[i-k][j-k];
            sq = abs(sq);
            g = gcd(g,sq);
        }
    }
    if(su==0)cout<<"YES\n";
    else if(g==0)cout<<"NO\n";
    else if(su%g==0)cout<<"YES\n";
    else cout<<"NO\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}