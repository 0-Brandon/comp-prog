#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr array<int,15> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
void solve(){
    int n;cin>>n;
    vector<int> x(n);
    bool b = false;
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    for(int i=1; i<n; i++)if(x[i]==x[i-1])b=true;
    if(b){cout<<"NO\n";return;}
    for(auto& p:primes){
        vector<int> cnt(p);
        for(int i=0; i<n; i++){
            cnt[x[i]%p]++;
        }
        int mi = INT_MAX;
        for(auto& i:cnt)mi = min(mi,i);
        if(mi>=2){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}