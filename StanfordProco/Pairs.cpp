#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<set<int>> s(2);
    for(int i=0; i<n; i++){
        string s1;
        cin>>s1;
        s[0].push_back(s1);
    }
    int m;cin>>m;
    for(int i=0; i<m; i++){
        string s1;
        cin>>s1;
        s[1].push_back(s1);
    }
    string st;cin>>st;
    for(int i=0; i<st.size(); i++){
        for(int j=i; j>=0; j--){
            for(int k=0; k<2; k++){
                if(s[k].find(substr(j,i-j))!=s[k].end()){
                    dp[i][k] = min(dp[i][k],dp[j-1][k^1]+1);
                }
            }
        }
    }
    if(dp.back()[0]==inf&&dp.back()[1]==inf)dp.back()[1]=-1;
    cout<<min(dp.back()[0],dp.back()[1]);
}