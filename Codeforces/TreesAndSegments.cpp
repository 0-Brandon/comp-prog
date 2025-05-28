#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> ans(n,0);
    auto f = [&](){
        vector<vector<int>> dp(n+1, vector<int>(k+1,0));
        dp[0][0]=s[0]=='0';
        if(1<=k)dp[0][1]=(s[0]!='0');
        for(int i=1; i<n; i++){
            for(int j=0; j<=k; j++){
                if(s[i]=='0')dp[i][j]=dp[i-1][j]+1;
                else if(s[i]=='1'&&j>0)dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                if(i>0)dp[i][j]=max(dp[i-1][j],dp[i][j]);
                if(j>0)dp[i][j]=max(dp[i][j-1],dp[i][j]);
            }
        }
        //dp[i][j] is max consecutive 0s ending no further than i with cost <=j;
        vector<int> dpl(n+1,-1);
        for(int i=1; i<=n; i++){
            int cnt = 0;
            for(int j=i; j<=n; j++){
                if(j>i)cnt+=(s[j-1]=='0');
                if(cnt<=k)dpl[j-i]=max(dpl[j-i], dp[i-1][k-cnt]);
            }
        }
        int cnt1= 0 ;
        for(int i=0; i<n; i++){
            cnt1+=s[i]=='0';
        }
        if(cnt1<=k)dpl[n]=0;
        for(int i=1; i<=n; i++){ 
            for(int j=0; j<=n; j++){
                if(dpl[j]!=-1)ans[i-1]=max(ans[i-1],dpl[j]*i+j);
            }
        }
    };
    f();
    reverse(s.begin(),s.end());
    f();
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }    
}