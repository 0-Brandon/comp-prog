#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes,id(1e7+5);
vector<int> lp(1e7+5,0),g(1e7+5);
void solve(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        ans^=g[a];
    }
    if(ans==0)cout<<"Bob\n";
    else cout<<"Alice\n";
}
signed main(){
    for(int i=2; i<1e7+5;i++){
        if(lp[i]==0){
            lp[i]=i;
            primes.push_back(i);
        }
        for(int j=0; i*primes[j]<1e7+5; j++){
            lp[i*primes[j]]=primes[j];
            if(primes[j]==lp[i])break;
        }
    }
    for(int i=0; i<primes.size(); i++)id[primes[i]]=i+1;
    g[1]=1;
    for(int i=2; i<1e7+5; i++){
        if(i%2==0)g[i]=0;
        else if(lp[i]==i)g[i] = id[i];
        else g[i] = g[lp[i]];
    }
    int t;cin>>t;
    while(t--){
        solve();
    }
}