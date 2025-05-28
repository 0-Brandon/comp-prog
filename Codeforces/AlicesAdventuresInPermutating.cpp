#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, b, c;
    cin>>n>>b>>c;
    if(n==1&&b==0&&c==0)cout<<"0\n";
    else if(n==2&&b==0&&c==0)cout<<"1\n";
    else if(b==0&&c==0||(b==0&&c<n-2))cout<<"-1\n";
    else if(b==0){
        cout<<n-(c<n)<<"\n";
    }
    else{
        int x = max(0LL,(n-c-1)/b);
        cout<<n-x-(c<n)<<"\n";
    }
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}