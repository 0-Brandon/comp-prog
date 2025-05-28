#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<array<int,2>> x(n);
    int a = 0, b=0;
    for(int i=0; i<n; i++){
        cin>>x[i][0];
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        cin>>x[i][1];
        a+=max(x[i][1],x[i][0]);
    }
    for(int i=0; i<n; i++){
        ans = max(ans,a-max(x[i][0],x[i][1])+x[i][0]+x[i][1]);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}