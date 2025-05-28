#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<int,int> cnt;
    for(int i=0; i<4*n; i++){
        cnt[s[i]]++;
    }
    int ans = 0;
    for(auto& [i,j]:cnt){
        if(i!='?')ans+=max(0,j-n);
    }
    ans+=cnt['?'];
    ans = 4*n-ans;
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}