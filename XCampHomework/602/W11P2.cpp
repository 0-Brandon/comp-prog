#include <bits/stdc++.h>


using namespace std;

int main(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n;i++){
        cin>>a[i];
    }
    int m; cin>>m;
    vector<int> b(m+1);
    for(int i=1; i<=m; i++){
        cin>>b[i];
    }
    vector<int> pre(m+1);
    vector<int> dp(m+1);
    for(int i=1; i<=n; i++){
        int p = 0;
        for(int j=1; j<=m; j++){
            if(b[j]<a[i]&&dp[p]<dp[j])p=j;
            else if(a[i]==b[j])dp[j] = dp[p]+1, pre[j] = p;
        }
    }
    int ap =0;
    int ans = 0;
    for(int i=1; i<=m; i++){
        if(dp[i]>ans)ans = dp[i], ap= i;
    }
    vector<int> aans;
    cout<<ans<<"\n";
    while(ap){
        aans.push_back(b[ap]);
        ap = pre[ap];
    }
    for(int i=aans.size()-1; i>=0; i--)cout<<aans[i]<<" ";cout<<"\n";
}