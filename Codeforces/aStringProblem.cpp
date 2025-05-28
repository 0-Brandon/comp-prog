#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string s;cin>>s;
    int n=s.size();
    vector<int> nxt(n,n);
    for(int i=n-1; i>=0; i--){
        if(s[i]!='a')nxt[i]=i;
        else if(i<n-1)nxt[i] = nxt[i+1];
    }
    if(nxt[0]==n){cout<<n-1<<"\n";return;}
    int f = nxt[0];
    string s2="";
    for(int i=f; i<n; i++)s2+=s[i];
    vector<int> z(s2.size(),0);
    z[0]=n;
    int l=0,r=0;
    for(int i=1; i<s2.size(); i++){
        if(i<r)z[i] = min(z[i-l],r-i);
        while(i+z[i]<s2.size()&&s2[i+z[i]]==s2[z[i]])z[i]++;
        if(i+z[i]>r)l=i,r=i+z[i];
    }
    int ans = 0;
    for(int l=1; l+f<=n; l++){
        int i = 0;
        int m = INT_MAX;
        bool b = true;
        while(i<n){
            if(nxt[i]==n)break;
            m = min(m,nxt[i]-i);
            i = nxt[i];
            if(z[i-f]<l){b = false;break;}
            i+=l;
        }
        if(b)ans+=m+1;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}