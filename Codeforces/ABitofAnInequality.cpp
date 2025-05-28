#include <bits/stdc++.h>
constexpr int LOG = 30;
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<vector<vector<int>>> pref(LOG, vector<vector<int>>(n+1,vector<int>(2,0))),suf(LOG, vector<vector<int>>(n+1,vector<int>(2,0)));
    for(int i=0;i<LOG; i++){
        for(int j=0; j<n; j++){
            int b = (x[j]>>i)&1;
            for(int k=0; k<2; k++)pref[i][j+1][k] = (k==b)+pref[i][j][k^b];
        }
        for(int j=n-1; j>=0; j--){
            int b = (x[j]>>i)&1;
            for (int k=0; k<2; k++)suf[i][j][k] = (k==b)+suf[i][j+1][k^b];
        }
    }
    //0 xxxx
    //xxxx 0
    long long ans = 0;
    for(int i=0; i<n; i++){
        int b = 31-__builtin_clz(x[i]);
        //highest set bit is b
        //we want pref[b][i][0]*suf[b][i][1]
        //or pref[b][i][1]*suf[b][i][0]
        ans+= 1LL*(1+pref[b][i][0])*suf[b][i+1][1];
        ans+= 1LL*pref[b][i][1]*(suf[b][i+1][0]+1);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}