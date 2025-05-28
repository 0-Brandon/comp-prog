

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    if(n%2==0)cout<<string(n-2,'3')+"66\n";
    else{
        if(n<=3)cout<<"-1\n";
        else cout<<string(n-5,'3')+"36366\n";
    }
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}