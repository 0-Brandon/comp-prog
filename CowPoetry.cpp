#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod=1000000007;
int exp( int a, int b){
    int res=1;
    for(;b>0;b>>=1){
        if(b&1){
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
    }
    return res;
}
signed main(){
    freopen("poetry.out","w",stdout);
    freopen("poetry.in","r",stdin);
    int n, m, k;
    cin>>n>>m>>k;
    map<char,int> lines;
    map<int,int> lcew;
    map<int,vector<int>> words;
    vector<int> word;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        words[b].push_back(a);
        word.push_back(a);
    }
    for(int i=0; i<m; i++){
        char a;
        cin>>a;
        lines[a]++;
    }
    vector<int> dp(k+1,0);
    dp[0]=1;
    for(int i=0; i<=k; i++){
        for(int j=0; j<n; j++){
            if(i-word[j]>=0)dp[i]=(dp[i]+dp[i-word[j]])%mod;
        }
    }
    for(auto& [i, j]:words){
        for(auto& l:j){
            lcew[i]=(lcew[i]+dp[k-l])%mod;
        }
    }
     int ans=1;
    for(auto& [i,numl]:lines){
        int curgroup=0; 
        for(auto& [endgroup,num]: lcew){
            curgroup+=exp(num,numl);
            curgroup%=mod;
        }
        ans*=curgroup;
        ans%=mod;
    }
    cout<<ans<<'\n';
}