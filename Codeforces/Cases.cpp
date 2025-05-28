#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, c, k;cin>>n>>c>>k;
    vector<vector<int>> pref(n+1,vector<int>(26));
    string s;cin>>s;
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i];
        pref[i+1][s[i]-'A']++;
    }
    vector<bool> bad((1<<c));
    bad[(1<<(s.back()-'A'))^((1<<c)-1)]=true;
    for(int i=0; i+k<=n; i++){
        int cur=0;
        for(int j=0; j<26; j++){
            if(pref[i+k][j]-pref[i][j]>0)cur|=1<<j;
        }
        bad[(cur)^((1<<c)-1)]=true;
    }
    int ans = INT_MAX;
    for(int i=bad.size()-1; i>=0; i--){
        if(!bad[i]){ans = min(ans,__builtin_popcount(i));continue;}
        for(int j=0; j<c; j++){
            if((i>>j)&1)bad[i^(1<<j)]=true;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}