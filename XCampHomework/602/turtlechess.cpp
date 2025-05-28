#include <bits/stdc++.h>

using namespace std;

int dp[41][41][41][41];
//number of each card you have used
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<int> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    dp[0][0][0][0]=x[0];
    vector<int> mp(4);
    for(int i=0;i<m;i++)
    {
        int t;
        cin>>t;
        mp[t-1]++;
    }
    for(int a=0;a<=mp[0];a++)for(int b=0;b<=mp[1];b++)for(int c=0;c<=mp[2];c++)for(int d=0;d<=mp[3];d++)
    {
        int id=a+b*2+c*3+d*4;
        int& cur = dp[a][b][c][d];
        //if we've used that card then we can transition with it
        if(a!=0)cur=max(cur,dp[a-1][b][c][d]+x[id]);
        if(b!=0)cur=max(cur,dp[a][b-1][c][d]+x[id]);
        if(c!=0)cur=max(cur,dp[a][b][c-1][d]+x[id]);
        if(d!=0)cur=max(cur,dp[a][b][c][d-1]+x[id]);
    }
    cout<<dp[mp[0]][mp[1]][mp[2]][mp[3]];
}