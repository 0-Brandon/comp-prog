#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> div(n+1);
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i)div[j].push_back(i);
    }
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[i]=i;
    }
    vector<vector<int>> reva(n+1),revb(n+1);
    long long ans = 0;
    for(int i=1; i<=n; i++){
        int g = gcd(a[i],b[i]);
        a[i]/=g;
        b[i]/=g;
        reva[a[i]].push_back(i);
        revb[b[i]].push_back(i);
    }
    
    vector<int> s(n+1,0);
    for(int i=1; i<=n; i++){
        for(int j=1; j*i<=n; j++){
            for(auto& id:reva[j*i])s[b[id]]++;
        }
        for(auto& id:revb[i]){
            for(auto& d:div[a[id]])ans+=s[d];
        }
        for(int j=1; j*i<=n; j++){
            for(auto& id:reva[j*i])s[b[id]]--;
        }
    }
    for(int i=1; i<=n; i++)ans-=(b[i]==1);
    cout<<ans/2<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
