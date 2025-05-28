#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,te;
void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> x(k);
    for(int i=0; i<k; i++){
        cin>>x[i];
    }
    int cnt = 0;
    int th = 0;
    for(int i=0; i<k; i++){
        if(x[i]>=3*m)th++;
        if(x[i]>=2*m)cnt+=x[i]/m;
    }
    if(!(th==0&&n%2==1)&&cnt>=n){cout<<"Yes\n";return;}
    cnt = 0;
    th = 0;
    for(int i=0; i<k; i++){
        if(x[i]>=3*n)th++;
        if(x[i]>=2*n)cnt+=x[i]/n;
    }
    if(!(th==0&&m%2==1)&&cnt>=m){cout<<"Yes\n";return;}
    cout<<"No\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    te=t;
    while(t--)solve();
}