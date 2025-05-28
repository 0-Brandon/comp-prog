#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n);
    for(int i=1; i<n; i++){
        int a;cin>>a;a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 0;
    int s = 0;
    auto dfs = [&](auto dfs, int i, int p) -> set<int>* {
        set<int>* cur=nullptr;
        vector<int> cs;
        for(auto& c:adj[i]){
            if(c!=p){
                set<int>* ch = dfs(dfs,c,i);
                cs.push_back(ch->size()+!(ch->find(x[i])!=ch->end()));
                if(!cur||ch->size()+!(ch->find(x[i])!=ch->end())>=cur->size()){
                    swap(ch,cur);
                    cur->insert(x[i]);
                }
            }
        }
        sort(cs.rbegin(),cs.rend());
        if(cs.size()>=2)ans = max(ans,cs[0]*cs[1]);
        if(!cur)
        {
            cur = new set<int>();
            cur->insert(x[i]);
        }
        if(i==0&&cs.size())s =cs[0]; 
        return cur;
    };
    dfs(dfs,0,0);
    cout<<max(ans,s)<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}