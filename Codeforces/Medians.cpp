#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    if(n==1&&k==1){cout<<"1\n1\n";return;}
    if(n==k||k==1){cout<<"-1\n";return;}
    if(k%2==0){
        cout<<"3\n1 "<<k<<" "<<k+1<<"\n";
    }
    else{
        cout<<"3\n1 "<<k-1<<" "<<k+2<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}