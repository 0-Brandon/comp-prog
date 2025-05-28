#include <bits/stdc++.h>

using namespace std;
int midx(vector<int> x, int y, int j){
    for(int i=j; i<x.size(); i++){
        if(x[i]>y){
            return i-1;
        }
    }
    return x.size()-1;
}
int main(){
    int n, boots;
    cin>>n>>boots;
    vector<int> x(n);
    vector<pair<int,int>> b(boots);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    for(int i=0; i<boots; i++){
        cin>>b[i].first>>b[i].second;
    }
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=dp[i]; j<boots; j++){
            int k = midx(x,b[j].first,i);
            k=min(k,i+b[j].second);
            cout<<dp[i]+j-dp[i];
            dp[k]=min(dp[k],dp[i]+j-dp[i]);
        }
    }
    cout<<dp[n-1];
}