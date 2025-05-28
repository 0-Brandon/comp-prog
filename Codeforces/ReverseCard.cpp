#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    int ans = 0;
    //Hard
    /*
    for(int i=1; i*i<=n; i++){
        for(int j=1; j*j<=m; j++){
            if(gcd(i,j)!=1)continue;
            int mg = min(n/i, m/j);//biggest g is such that xg<n and yg<m
            ans+=mg/(i+j);//every multiple of (x+y) up to mg works
        }
    }*/
    //Easy
    for(int b=1; b<=m; b++){
        ans+=(n+b)/(b*b);
    }
    cout<<ans-1<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
/*
x + y is multiple of y*g
x % (g-1)*y ==0
iterate over y from 1 to m
iterate over g from y to m/y


a= xg b = yg
a/b

y must be 1

a+b is multiple of b^2
a is k*b^2-b
iterate over b
a+b is multiple of b^2
a%b^2 + b%b^2 =0;
a=b^2-b % b^2


a%b^2+b%b^2=0

a, a+b^2, a+2*b^2
*/