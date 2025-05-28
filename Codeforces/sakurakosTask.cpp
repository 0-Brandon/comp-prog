#include <bits/stdc++.h>

using namespace std;

int te,t;
void solve(){
    int n,k;cin>>n>>k;
    vector<int> x(n);
    int g = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        g = gcd(g,x[i]);
    }
    if(n==1){
        if(k<=x[0])cout<<k-1<<"\n";
        else cout<<k<<"\n";
        return;
    }
    for(int i=0; i<n; i++){
        x[i] = g*i;
    }
    //0,1
    //k=3
    for(int i=0; i<n; i++){
        if(k+i<=x[i]){
            cout<<k+i-1<<"\n";
            return;
        }
    }
    cout<<k+n-1<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;te=t;
    while(t--)solve();
}