#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m; cin>>n>>m;
    map<int,vector<int>> mp;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        mp[x[i]].push_back(i);
    }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;cin>>a>>b;
        a--,b--;
        if(x[a]>x[b]||x[a]==x[b]&&a>b)adj[a].push_back(b);
        else adj[b].push_back(a);
    }
    vector<int> e(n);
    vector<int> fail(n,false);
    auto par =[&](auto&& par, int i)->pair<int,int> {
        if(e[i]<0)return make_pair(i,fail[i]);
        auto[a,b] = par(par,e[i]);
        fail[i]|=b;
        e[i] = a;
        return make_pair(a,fail[i]);
    };
    auto merge = [&](int i,int j){
        i =par(par,i).first,j = par(par,j).first;
        if(i==j)return;
        if(e[i]>e[j])swap(i,j);
        e[i]+=e[j];
        e[j] = i;
    };
    for(auto& [sz,nodes]:mp){
        for(auto& i:nodes){
            e[i] = -sz;
            for(auto& j:adj[i]){
                if(-e[par(par,j).first]>=sz){
                    merge(i,j);
                }else{
                    fail[par(par,j).first]=true;
                    merge(i,j);
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        par(par,i);
        cout<<!fail[i];
    }
}