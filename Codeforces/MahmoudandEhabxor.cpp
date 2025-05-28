#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, x;
    cin>>n>>x;
    if(n==2){
        if(x==0)cout<<"NO";
        else cout<<"YES\n"<<0<<" "<<x;
        return;
    }
    if(n==1){
        cout<<"YES\n"<<x<<"\n";
        return;
    }
    cout<<"YES\n";
    int s=0;
    for(int i=1; i<=n-3; i++){
        cout<<i<<" ";
        s^=i;
    }
    int pw = 1<<17;
    if(s==x){cout<<pw<<" "<<pw*2<<" "<<((pw*2)^pw);return;}
    cout<<0<<" "<<pw<<" "<<(pw^s^x);
}
int main(){
    solve();
}