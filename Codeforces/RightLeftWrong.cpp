#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    string s;cin>>s;
    int ans = 0;
    vector<int> pref(n+1);
    for(int i=0; i<n; i++)pref[i+1] = pref[i]+x[i];
    int i=0, j=n-1;
    while(i<j){
        while(i+1<j&&s[i]!='L')i++;
        while(j-1>i&&s[j]!='R')j--;
        if(s[j]=='R'&&s[i]=='L')ans+=pref[j+1]-pref[i];
        i++,j--;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}