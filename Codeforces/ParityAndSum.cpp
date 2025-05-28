#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    int m = 0, e=0;
    vector<int> ev;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]%2==0){e = max(e,x[i]);ev.push_back(x[i]);}
        else m = max(m,x[i]);
    }
    bool b= true;
    for(int i=1; i<n; i++){
        if(x[i]%2!=x[i-1]%2)b=false;
    }
    if(b){cout<<"0\n";return;}
    if(m>e){cout<<ev.size()<<"\n";return;}
    sort(ev.begin(),ev.end());
    if(ev[0]>m){cout<<ev.size()+1<<"\n";return;}
    m = ev[0]+m;
    b=true;
    for(int i=1; i<ev.size(); i++){
        if(m<ev[i])b=false;
        m+=ev[i];
    }
    if(b)cout<<ev.size()<<"\n";
    else cout<<ev.size()+1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}