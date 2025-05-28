#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    map<vector<int>,int> h;
    map<int,int> sym;
    int c = 0;
    auto dfs = [&](auto dfs,int i, int p)->int {
        vector<int> ch;
        map<int,int> chc;
        for(auto& c:adj[i])if(c!=p){
            int temp = dfs(dfs,c,i);
            ch.push_back(temp);
            chc[temp]++;
        }
        sort(ch.begin(),ch.end());
        int id = 0;
        int bc=0;
        for(auto& i:chc)if(i.second&1)bc++,id=i.first;
        int ha =0;
        if(h.count(ch))ha = h[ch];
        else(h[ch]=c++, ha = h[ch]);
        sym[ha] = (bc==0)||(bc==1&&sym[id]);
        return ha;
    };
    cout<<(sym[dfs(dfs,0,0)]?"YES":"NO")<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}