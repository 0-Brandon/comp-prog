#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ma = abs(x[0]), mi = x[0];
    for(int i=1; i<n; i++){
        int nma, nmi;
        nma = max({ma+x[i],abs(mi+x[i])});
        nmi = x[i]+mi;
        ma = nma, mi = nmi;
    }
    cout<<ma<<"\n";
}
*/ //easy

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ma = abs(x[0]), mi = x[0];
    int mant = 1, mint = 1;
    if(ma==mi)mant = mint=2;
    for(int i=1; i<n; i++){
        int nma, nmi;
        if(abs(mi+x[i])>ma+x[i]){
            mant = mint;
        }
        else if(abs(mi+x[i])==ma+x[i]){
            mant += mint;
        }
        nma = max({ma+x[i],abs(mi+x[i])});
        nmi = mi+x[i];
        ma = nma, mi = nmi;
    }
    cout<<mant<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}
