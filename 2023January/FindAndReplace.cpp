#include <bits/stdc++.h>


using namespace std;
void solve(){
    set<char> x;
    vector<int> adj(52,-1);
    vector<int> ind(52,0);
    int ans = 0;
    string a, b;
    cin>>a>>b;
    for(int i=0; i<a.size(); i++){
        if( adj[((a[i]>='a')?(a[i]-'a'):(a[i]-'A'+26))]!=-1&& adj[((a[i]>='a')?(a[i]-'a'):(a[i]-'A'+26))]!=((b[i]>='a')?(b[i]-'a'):(b[i]-'A'+26))){
            cout<<-1<<"\n";
            return;
        }
        adj[((a[i]>='a')?(a[i]-'a'):(a[i]-'A'+26))]=((b[i]>='a')?(b[i]-'a'):(b[i]-'A'+26));
        x.insert(b[i]);
    }
    if(x.size()==52){
        if(a==b)cout<<0<<"\n";
        else cout<<-1<<"\n";
        return;
    }
    vector<int> visited(52, -2);
    for(int i=0; i<52; i++){
        if(adj[i]!=i&&adj[i]!=-1){
            ans++;
            ind[adj[i]]++;
        }
    }
    for(int i=0; i<52; i++){
        if(visited[i]==-2){
            bool flag = false;
            int a = i;
            while(a!=-1&&visited[a]==-2){
                visited[a]=i;
                a=adj[a];
            }
            if(a==-1||adj[a]==a||visited[a]!=i) flag = true;
            if(!flag){
                int cs = a;
                do{
                    visited[a]=-1;
                    if(ind[a]>1) {
                        flag = true;
                    }
                    a=adj[a];
                }while(!flag&&a!=cs);
            }
            if(!flag)ans++;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}