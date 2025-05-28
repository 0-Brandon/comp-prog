#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("cowpatibility.in","r",stdin);
    freopen("cowpatibility.out","w",stdout);
    int n;cin>>n;
    vector<map<set<int>,int>> mp(6);
    for(int i=0; i<n; i++){
        vector<int> cur(5);
        for(int j=0; j<5; j++)cin>>cur[j];
        for(int j=(1<<5)-1; j>=0; j--){
            set<int> s;
            for(int k=0; k<5; k++){
                if(j&(1<<k)){
                    s.insert(cur[k]);
                }
            }
            mp[__builtin_popcount(j)][s]++;
        }
    }
    int ans = 0;
    int mul = 1;
    for(int i=1; i<=5; i++){
        for(auto& [s,c]:mp[i]){
            ans += mul*c*(c-1)/2;
        }
        mul*=-1;
    }
    cout<<n*(n-1)/2-ans<<"\n";
}