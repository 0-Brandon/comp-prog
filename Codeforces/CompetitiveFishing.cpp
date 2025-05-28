#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    string s1;
    cin>>s1;
    int cnt = 0;
    vector<int> s;
    for(int i=n-1; i>0;i--){
        cnt+=((s1[i]=='1')?(1):(-1));
        s.push_back(cnt);
    }
    sort(s.rbegin(),s.rend());
    int cur = 0;
    for(int i=0; i<n-1; i++){
        if((cur+=s[i])>=k){
            cout<<i+2<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}