#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;cin>>n>>k;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        mp[a]++;
    }
    vector<pair<int,int>> x;
    for(auto& i:mp)x.push_back(i);
    int ans =0, cur = 0, l = 0;
    for(int i=0; i<x.size(); i++){
        while(i-l>=k){
            cur-=x[l].second;
            l++;
        }
        if(i==0||(x[i].first == x[i-1].first+1)){
            cur+=x[i].second;
        }else{
            l = i, cur = x[i].second;
        }
        ans = max(ans,cur);

    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}