#include <bits/stdc++.h>

using namespace std;

int calc(vector<int>& a){
    int par = a.size()%2;
    vector<bool> vis(a.size());
    for(int i=0; i<a.size(); i++){
        if(!vis[i]){
            for(int id = i;!vis[id];id = a[id])vis[id]=true;
            par^=1;
        }
    }
    return par;
}
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];a[i]--;
    }
    for(int i=0; i<n; i++){
        cin>>b[i];b[i]--;
    }
    vector<int> c = a, d = b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    if(c!=d){
        cout<<"NO\n";
        return;
    }
    for(int i=0; i<n; i++){
        a[i] = lower_bound(c.begin(),c.end(),a[i])-c.begin();
        b[i] = lower_bound(d.begin(),d.end(),b[i])-d.begin();
    }
    if(calc(a)!=calc(b)){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}