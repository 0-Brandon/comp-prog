#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    string t;
    cin>>t;
    bool E = t[0]==t[1];
    int c = s.back()==t[1];
    //max number of occurences given
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1, vector<int>(n+1)));
    for(int i=n-2; i>=0; i--){
        c+=s[i]==t[1];
        for(int j=k; j>0; j--){
            for(int l=0; l<c+j; l++){
                //how do we denote if its even possible to have l second ones?
                dp[i][j-(s[i]!=t[1])][l+1] = max(dp[i][j-(s[i]!=t[1])][l+1], dp[i+1][j][l]+E*l);
                dp[i][j-(s[i]!=t[0])][l+E] = max(dp[i][j-(s[i]!=t[0])][l+E],dp[i+1][j][l]+l);
            }
        }
    }
    cout<<*max_element(dp[0][0].begin(),dp[0][0].end());
}
//a b .
//at each step, we either turn into a or b
//if we turn into b, we add number of a before this to ans
//go back t front
//keep track of number of bs in front
//we can either increase bcount by 1 (which might cost a move)
//or we can add bcount to ans ( which might cost a move)
//dp[i][j][k] ith index, j is number of moves left, k is bcount
//E is whether a==b