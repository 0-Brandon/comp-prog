#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin>>x[i];
    }
    priority_queue<pair<int,int>> d;
    vector<int> nxt(n);
    vector<int> prev(n);
    vector<bool> r(n,false);
    for(int i=0; i<n; i++){
        nxt[i] = i+1;
        prev[i] = i-1;
        if((nxt[i]!=n&&x[nxt[i]]+1==x[i])||(prev[i]!=-1&&x[prev[i]]+1==x[i])){
            d.push(make_pair(x[i],i));
            r[i]=true;
        }
    }
    int b = 0;
    while(!d.empty()){
        auto [l,i] = d.top();
        d.pop();
        if(prev[i]!=-1&&nxt[i]!=n&&x[nxt[i]]-x[prev[i]]==1&&!r[nxt[i]])d.push(make_pair(x[nxt[i]],nxt[i])),r[nxt[i]]=true;
        if(prev[i]!=-1&&nxt[i]!=n&&x[prev[i]]-x[nxt[i]]==1&&!r[prev[i]])d.push(make_pair(x[prev[i]],prev[i])),r[prev[i]]=true;
        if(prev[i]!=-1)nxt[prev[i]]=nxt[i];
        if(nxt[i]!=n)prev[nxt[i]]=prev[i];
    }
    bool a = true;
    for(int i=0; i<n; i++){
        if(!r[i]&&x[i]!=0)a=false;
        if(!r[i])b++;
    }
    if(b==1&&a)cout<<"YES\n";
    else cout<<"NO\n";
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}

