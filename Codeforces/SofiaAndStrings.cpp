#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<vector<int>> x(26);
    for(int i=0; i<n; i++){
        x[s[i]-'a'].push_back(i);
    }
    vector<int> pos(26,-1);
    for(auto& i:t){
        int id = i-'a';
        int m = -1;
        for(int j=id; j<26; j++){
            m = max(m,pos[j]);
        }
        auto it = upper_bound(x[id].begin(),x[id].end(),m);
        if(it==x[id].end()){
            cout<<"NO\n";return;
        }
        pos[id] = *it;
    }
    cout<<"YES\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}