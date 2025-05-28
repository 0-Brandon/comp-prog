#include <bits/stdc++.h>

using namespace std;
int dist(pair<int, int>& a, pair<int,int>& b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main(){
    freopen("marathon.out", "w",stdout);
    freopen("marathon.in","r",stdin);
    //dp[i][k] is min distance to get to node [i] iwth k skips
    //dp[i][k] is just min(dp[i-k][0]+dist(i-k,i), dp[i-k+1][1]+dist(i-k,i));
    int n, k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1, vector<int> (k+1, 10000000));
    vector<pair<int, int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
    }
    for(int i=0; i<=k; i++){
        dp[0][i]=0;
    }
     for(int kc=0; kc<=k; kc++){
        for(int i=0; i<=n; i++){
            for(int j=0, l=1; j<=k-kc&&i+l<=n; j++, l++){
                dp[i+l][j+kc] = min(dp[i+l][j+kc], dp[i][kc]+dist(x[i], x[i+l]));
            }
        }
    }
    /*for(int i=0; i<=n; i++){
        cout<<"i: "<<i<<"\n";
        for(int j=0; j<=k; j++){
            cout<<"k: "<<j<<" ";
            cout<<dp[i][j]<<"\n";
        }
        cout<<"\n";
    }*/
    cout<<*min_element(dp[n-1].begin(), dp[n-1].end());
}