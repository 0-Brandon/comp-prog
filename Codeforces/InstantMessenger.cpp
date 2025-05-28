#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m, q;
    cin>>n>>m>>q;
    vector<set<int>> adj(n);
    vector<bool> onl(n,false);
    vector<int> ans(n,0);
    auto add = [&](int u, int v){
        if(adj[u].size()>adj[v].size())swap(u,v);
        adj[u].insert(v);
        ans[v]+=onl[u];
    };
    auto rem = [&](int u, int v)->void {
        if(!adj[u].count(v))swap(u,v);
        adj[u].erase(v);
        ans[v]-=onl[u];
    };
    auto query = [&](int i)->int {
        int aans=ans[i];
        for(auto& j:adj[i]){
            aans+=onl[j];
        }
        return aans;
    };
    auto on = [&](int i)->void {
        onl[i]=true;
        for(auto& j:adj[i])ans[j]++;
    };
    auto off = [&](int i)->void {
        onl[i]=false;
        for(auto& j:adj[i])ans[j]--;
    };
    int o;cin>>o;
    for(int i=0; i<o; i++){
        int a;cin>>a;a--;
        on(a);
    }
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        a--,b--;
        add(a,b);
    }
    for(int i=0; i<q; i++){
        char t;int a, b;cin>>t;
        if(t=='O'){cin>>a;a--;on(a);}
        if(t=='F'){cin>>a;a--;off(a);}
        if(t=='A'){cin>>a>>b;a--,b--;add(a,b);}
        if(t=='D'){cin>>a>>b;a--,b--;rem(a,b);}
        if(t=='C'){cin>>a;a--;cout<<query(a)<<"\n";}
    }
}