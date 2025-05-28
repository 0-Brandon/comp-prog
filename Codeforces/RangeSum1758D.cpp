#include <bits/stdc++.h>
//solution doesn't use distinct nums unfortunately
using namespace std;
void solve(){
    int n;
    cin>>n;
    if(n==3){
        cout<<"1 4 4"<<"\n";
        return;
    }
    if(n==2){
        cout<<"3 6"<<"\n";
        return;
    }
    cout<<"1 "<<n-2<<" "<<n-2<<" "<<n<<" ";
    for(int i=4; i<n; i++){
        cout<<n-1<<" ";
    }
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}