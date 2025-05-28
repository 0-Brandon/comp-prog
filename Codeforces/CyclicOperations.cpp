
#include <bits/stdc++.h>
 
using namespace std;
vector<int> x;
vector<bool> visited;
int n, k;
bool ans = true;
void dfs(int i){
    int s = x[i], f = x[x[i]];
    while(s!=f){
        if(visited[s]){
            while(!visited[i])visited[i]=true, i = x[i];
            return;
        }
        if(visited[f]){
            while(!visited[i])visited[i]=true, i = x[i];
            return;
        }
        s=x[s],f=x[x[f]];
    }
    s=i;
    while(s!=f){
        s=x[s], f = x[f];
    }
    s = x[s];
    int c=1;
    while(s!=f)s=x[s],c++;
    if(c!=k)ans=false;
    while(i!=s)visited[i]=true, i = x[i];
    i = x[i];
    while(i!=s)visited[i]=true, i=x[i];
}
void solve(){
    cin>>n>>k;
    visited.assign(n,0);
    x.assign(n,0);
    ans=true;
    for(int i=0; i<n; i++)cin>>x[i], x[i]--;
    if(k==1){
        for(int i=0; i<n; i++)if(i!=x[i]){cout<<"NO\n";return;}
        cout<<"YES\n";
        return;}
    for(int i=0; i<n; i++){
        if(!visited[i])dfs(i);
        if(ans==false)break;
    }
    cout<<(ans?"YES":"NO")<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
