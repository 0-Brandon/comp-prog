#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    string b, e;
    cin>>b>>e;
    vector<int> cntb(11), cnte(11);
    for(int i=0; i<n; i++){
        if(b[i]=='+')b[i]='10';
        cntb[b[i]-'0']++;
    }
    for(int i=0; i<n; i++){
        if(e[i]=='+')e[i]='10';
        cnte[e[i]-'0']++;
    }

    vector<vector<int>> dp(n+1,vector<int> (n+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j+1]=
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
}