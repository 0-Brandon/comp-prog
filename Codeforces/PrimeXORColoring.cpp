#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    if(n==1){cout<<"1\n1\n";return;}
    if(n==2){cout<<"2\n1 2\n";return;}
    if(n<=6){
    cout<<ceil((n-1.0)/2)+1<<"\n";
    int c=1;
    for(int i=0; i<n; i++){
        cout<<c<<" ";
        if(i%2==0)c++;
    }
    cout<<"\n";
    return;
    }
    cout<<4<<"\n";
    int c = 2;
    for(int i=0; i<n; i++){
        cout<<c<<" ";
        c=(c)%4+1;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}