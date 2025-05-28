#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    vector<string> c(n);
    map<string,vector<string>> adj;
    set<pair<string,string>> xd;
    map<pair<string,string>,int> rev;
    set<string> nodes;
    map<string,int> ind;
    map<string,int> dib;
    map<string,bool> node;
    bool b = true;
    for(int i=0; i<n; i++){
        string s1,s2;cin>>s1>>s2;
        s[i] = s1.substr(0,3);
        c[i] = s2[0];
        if(xd.find({s[i],c[i]})!=xd.end()){b=false;}
        xd.insert({s[i],c[i]});
        rev[{s[i],c[i]}]=i;
        adj[s[i]].push_back(c[i]);
        dib[s[i]]++;
        ind[s[i].substr(0,2)+c[i]]++;
        nodes.insert(s[i]);
        node[s[i]]=true;
    }
    if(!b){cout<<"NO\n";exit(0);}
    vector<string> ans(n);
    map<string,bool> res;
    map<string,bool> vis;
    auto dfs = [&](auto dfs, string i)->void {
        if(vis[i])return;
        vis[i]=true;
      //  cout<<i<<"\n";
        if(dib[i]>=2){
            for(auto& c:adj[i]){
                string ne = i.substr(0,2)+c;
                if(res[ne]){cout<<"NO\n";exit(0);}
                res[ne]=true;
                ans[rev[make_pair(i,c)]] = ne;
                if(node[ne])dib[ne]++;
            }
        }
        if(dib[i]==1){
            ans[rev[make_pair(i,adj[i][0])]] = i;
            res[i]=true;
        }
        for(auto& c:adj[i]){
            dfs(dfs,i.substr(0,2)+c);
        }
    };
    for(auto& i:nodes){
        if(ind[i]==0||(ind[i]==1&&adj[i].size()>1)){
            dfs(dfs,i);
        }
    }
    for(auto& i:nodes){
        if(ind[i]==1&&adj[i].size()==1)dfs(dfs,i);
    }
    cout<<"YES\n";
    for(auto& i:ans)cout<<i<<"\n";
}