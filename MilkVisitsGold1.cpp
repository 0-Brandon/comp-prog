#include <bits/stdc++.h>
//it's over.
using namespace std;
int timer = 0;
constexpr int LOG  = 20;
constexpr int B = 1000;
vector<int> tin,tout;
vector<int> depth;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> tour;
void dfs(int i, int p){
    tin[i] = timer++;
    tour.push_back(i);
    depth[i] = depth[p]+1;
    up[0][i] = p;
    for(int j=1; j<LOG; j++){
        up[j][i] = up[j-1][up[j-1][i]];
    }
    for(auto& c:adj[i]){
        if(c==p)continue;
        dfs(c,i);
    }
    tout[i] = timer++;
    tour.push_back(i);
}
int lca(int a, int b){
    int d = depth[b]-depth[a];
    for(int i=0; i<LOG; i++,d>>=1){
        if(d&1)b = up[i][b];
    }
    if(a==b)return a;
    for(int i=LOG-1; i>=0; i--){
        if(up[i][a]!=up[i][b])a=up[i][a],b = up[i][b];
    }
    return up[0][a];
}
int main(){
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int n, q;
    cin>>n>>q;
    vector<int> x(n);
    adj.resize(n);
    up.resize(LOG, vector<int>(n));
    depth.resize(n);
    tin.resize(n);
    tout.resize(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0,0);
    vector<array<int,3>> queries;
    vector<int> ad;
    for(int i=0; i<q; i++){
        int a, b,c;cin>>a>>b>>c;
        a--,b--;
        if(depth[a]>depth[b])swap(a,b);
        int l = lca(a,b);
        if(l==a){
            queries.push_back({tin[a],tin[b],c});
            ad.push_back(-1);
        }
        else{
            queries.push_back({tout[a],tin[b],c});
            ad.push_back(l);
        }
    }
    vector<bool> ans(q);
    vector<int> s(q);
    iota(s.begin(),s.end(),0);
    sort(s.begin(),s.end(),[&](int i, int j){return queries[i][0]/B==queries[j][0]/B?queries[i][1]>queries[j][1]:queries[i][0]/B<queries[j][0]/B;});
    vector<int> cnt(n+1,0);
    vector<int> col(n+1,0);
    int l=queries[s[0]][0], r = queries[s[0]][0]-1;
    for(auto& i:s){
        int dl = queries[i][0], dr = queries[i][1], c = queries[i][2];
        while(l<dl){
            if(l!=-1){
                cnt[tour[l]]--;
                if(cnt[tour[l]]&1)col[x[tour[l]]]++; //this node is on path
                else col[x[tour[l]]]--; //even means its not on path
                l++;
            }
        }
        while(l>dl){
            --l;
            cnt[tour[l]]++;
            if(cnt[tour[l]]&1)col[x[tour[l]]]++; //this node is on path
            else col[x[tour[l]]]--; //even means its not on path
        }
        while(r<dr){
            r++;
            cnt[tour[r]]++;
            if(cnt[tour[r]]&1)col[x[tour[r]]]++; //this node is on path
            else col[x[tour[r]]]--; //even means its not on path
        }
        while(r>dr){
            if(r!=-1){cnt[tour[r]]--;
            if(cnt[tour[r]]&1)col[x[tour[r]]]++; //this node is on path
            else col[x[tour[r]]]--; //even means its not on path
            r--;
            }
        }
        bool b=false;;
        if(ad[i]!=-1&&x[ad[i]]==c)b = true;
        ans[i] = ((col[c]>0)|b);
        //this doesn't work
        //we assume that cnt[i] is even iff the node is not on the path, but we neglected that different nodes could have the same value
    }
    for(auto i:ans)cout<<i;
}