#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    int ans = 0;
    auto ok = [&](int t){
        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]&t]++;
            mp[(~b[i])&t]--;
        }
        for(auto& i:mp)if(i.second!=0)return false;
        return true;
    };
    for(int i=30; i>=0; i--){
        if(ok(ans|(1<<i))){
            ans|=1<<(i);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}