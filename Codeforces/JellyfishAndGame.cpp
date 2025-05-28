#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> x(n);
    vector<int> y(m);
    int xma=0, xmi=INT_MAX, yma=0, ymi=INT_MAX, ma=0, mi=INT_MAX, xsu = 0, ysu = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        xmi = min(xmi,x[i]);
        xma = max(xma, x[i]);
        ma = max(ma,x[i]);
        mi = min(mi,x[i]);
        xsu+=x[i];
    }
    for(int i=0; i<m; i++){
        cin>>y[i];
        ymi = min(ymi,y[i]);
        yma = max(yma, y[i]);
        ma = max(ma,y[i]);
        mi = min(mi,y[i]);
        ysu+=y[i];
    }
    int nxsu = xsu, nysu = ysu;
    if(yma>xmi){
        nxsu-=xmi,nysu+=xmi, nysu-=yma,nxsu+=yma;
    }
    if(k%2==1)cout<<nxsu<<"\n";
    else cout<<nxsu+mi-ma<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}