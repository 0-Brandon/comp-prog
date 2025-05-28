#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
        p[x[i]]=i;
    }
    bitset<1000000> b;
    int q;cin>>q;
    reverse(p.begin(),p.end());
    while(q--){
        string s;cin>>s;
        for(int i=0; i<n; i++){
            b[i] = (s[i]=='1');
        }
        vector<int> vis(n,false);
        int ans =INT_MAX;
        for(auto& i:p){
            if(b[i])continue;
            int cur = 1;
            bool f = true;
            for(int j=i; j>=0; j--){
                if(vis[j]){f=false;break;}
                if(x[j]<x[i]&&b[j]){break;}
                cur+=(x[j]>x[i]);
                vis[j] = true;
            }
            for(int j=i+1; j<n; j++){
                if(vis[j]){f=false;break;}
                if(x[j]<x[i]&&b[j]){break;}
                cur+=(x[j]>x[i]);
                vis[j] = true;
            }
            if(f)ans = min(ans,cur);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    solve();
}