#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> up;
vector<vector<int>> adj;
void init(int n);
vector<bool> r;
int n,q,LOG=20;
vector<int> s;
vector<int> dist;
vector<int> par;
vector<int> depth;
//initial decomposition is too slow
void upd(int i, int p){
    up[i][0]=p;
    for(auto& c:adj[i]){
        if(c!=p){
            depth[c]=depth[i]+1;
            upd(c,i);
        }
    }
}
void distp(){
    depth[0]=0;
    up[0][0]=0;
    upd(0,0);
    for(int i=1; i<=LOG; i++){
        for(int j=0; j<n; j++){
            up[j][i]=up[up[j][i-1]][i-1];
        }
    }
}
int dfs(int i,int p=0){
    s[i]=1;
    for(auto& c:adj[i])if(!r[c]&&c!=p)
        s[i]+=dfs(c,i);
    return s[i];
}
int fc(int n, int ms, int p=0){
    for(auto& i:adj[n])if(!r[i]&&i!=p&&s[i]*2>ms){
        return fc(i,ms,n);
    }
    return n;
}
void centroid(int n=0, int p=-1){
    int ce = fc(n,dfs(n),n);
    par[ce]=p;
    r[ce]=true;
    for(auto& i:adj[ce])if(!r[i]){
        centroid(i,ce);
    }
}
int lca(int a, int b){
    if(depth[a]>depth[b])swap(a,b);
    int d = depth[b]-depth[a];
    for(int i=LOG; i>=0; i--){
        if(d&(1<<i))b=up[b][i];
    }
    if(a==b)return a;
    for(int i=LOG; i>=0; i--){
        if(up[b][i]!=up[a][i])b=up[b][i],a=up[a][i];
    }
    return up[a][0];
}
int d(int a, int b){
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}
void update(int a){
    int x = a;
    do{
        dist[x]=min(dist[x],d(a,x));
        x=par[x];
    }while(x!=-1);
}
int query(int a){
    int x = a;
    int ans = 1e9;
    do{
        ans=min(ans,d(a,x)+dist[x]);
        x=par[x];
    }while(x!=-1&&x!=par[x]);
    return ans;
}
int main(){
    cin>>n>>q;
    init(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    distp();
    centroid();
    update(0);
    for(int i=0; i<q; i++){
        int t, a;
        cin>>t>>a;
        a--;
        if(t==1){
            update(a);
        }else{
            cout<<query(a)<<"\n";
        }
    }
}
void init(int n){
    adj.resize(n);
    r.resize(n,false);
    s.resize(n,0);
    dist.resize(n,1e9);
    up.resize(n,vector<int>(LOG+1));
    depth.resize(n);
    par.resize(n);
}