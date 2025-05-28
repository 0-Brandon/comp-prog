#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 0;
    int a=INT_MAX, b=INT_MAX;
    for(int i=0; i<n; i++){
        if(a>b)swap(a,b);
        if(x[i]<=a)a=x[i];
        else if(x[i]>b)ans++,a=x[i];
        else b=x[i];
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}