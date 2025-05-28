#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++){
        int a,b;cin>>a>>b;a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int med = 0;
    vector<int> leaf(n);
    auto dfs = [&](auto&& dfs, int i, int p)->void {
        for(auto& c:adj[i]){
            if(c!=p)dfs(dfs, c,i);
        }
        if(adj[i].size()==1&&i!=0)leaf[i]=true;
    };
    dfs(dfs,0,0);
    string s;cin>>s;
    vector<int> x(n);
    int ans =0;
    map<int,int> mp;
    mp['?']=0;
    mp[0]=0;
    mp[1]=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0'||s[i]=='1')x[i]=s[i]-'0';
        else x[i]='?';
        if(leaf[i]){
            mp[x[i]]++;
        }
        if(x[i]=='?'&&!leaf[i]&&i!=0)med++;
    }
    if(x[0]==0||x[0]==1){
        ans = mp[!x[0]]+((mp.rbegin()->second)+1)/2;
    }
    else{
        //if theres so many 1s, it may be optimial to just go for it and mark it as 0
        ans = max(mp[0],mp[1])+((mp.rbegin()->second))/2;
        //we spent one, so its round down
        if(mp[0]==mp[1]&&(mp.rbegin()->second%2==med%2)){
            ans = max(ans,mp[0]+((mp.rbegin()->second)+1)/2);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}

//it really is just whether the first and last numbers are equal, then its good
