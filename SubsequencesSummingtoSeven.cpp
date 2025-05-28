#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    freopen("div7.in","r",stdin);
    freopen("div7.out","w", stdout);
    vector<int> first(7,-1),last(7,0);
    int n;cin>>n;
    int pref=0;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        pref+=a;
        if(first[pref%7]==-1)first[pref%7]=i;
        last[pref%7]=i;
    }
    int ans=0;
    for(int i=0; i<7; i++){
        ans=max(ans, last[i]-first[i]);
    }
    cout<<ans<<"\n";
}