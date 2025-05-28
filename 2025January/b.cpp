#include <bits/stdc++.h>
#define int long long 
using namespace std;
struct DSU{
    vector<int> e, rt;
    DSU(int n):e(n,0), rt(n,0){iota(rt.begin(),rt.end(),0);}
    int par(int a){return rt[a]==a?a:rt[a] = par(rt[a]);}
    int get(int a){return e[par(a)];}
    bool merge(int a, int b){
        a=par(a),b=par(b);
        if(a==b)return false;
        if(e[a]<e[b])swap(a,b);
        e[a]+=e[b];
        rt[b] = a;
        return true;
    }
    void inc(int a){e[par(a)]++;}
};
signed main(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DSU dsu(n);
    vector<bool> alive(n);
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            //mark it as dead, don't add the edges
        }else{
            for(auto& c:adj[i]){
                if(!(s[c]=='0'))
                dsu.merge(i,c);
            }
        }
    }
    //now our graph contains all the edges, that exist at the end
    int ans = 0;
    vector<int> aans(n);
    for(int i=n-1; i>=0; i--){
        if(s[i]=='0'){
            //we need to add all edges
            dsu.inc(i);
            alive[i] = true;
            for(auto& c:adj[i]){
                if(!alive[c]&&s[c]=='0')continue;
                if(dsu.par(c)!=dsu.par(i)){
                    ans+=dsu.get(i)*dsu.get(c);
                }
                dsu.merge(i,c);
            }
        }else{
            //we mark this one as alive, but our edges are already added
            ans+=dsu.get(i); //add one for each node in our group
            dsu.inc(i); //increase alive count of group
            alive[i] = true;
        }
        aans[i] = ans;
    }
    for(auto& i:aans)cout<<i<<"\n";
}