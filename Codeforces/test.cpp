#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> x;
    for(int i=0; i<n;i++){
        for(int j=0; j<i; j++){
            x[i][j]=0;
        }
        for(int j=i; j<n; j++){
            cin>>x[i][j];
        }
    }
    //we take one number per row, only moving to the right
    //dp?
    vector<vector<int>> dp(n, vector<int>(n));
    set<int> s;
    for(int i=0; i<n; i++){
        int a = 0;
        for(int j=0; j<n; j++){
            dp[i][j] = a+x[i][j];
            if(i>0)a = max(a,dp[i-1][j]);
            s.insert(dp[i][j]);
        }
    }
    auto it = s.rbegin();
    while(k--){
        cout<<*it<<" ";
        --it;
    }
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}