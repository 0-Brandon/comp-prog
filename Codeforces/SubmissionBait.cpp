#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;cin>>n;
    bool b =false;
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        cnt[a]++;
    }
    for(auto& i:cnt)if(i.second%2==1)b=true;
    if(b)cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}