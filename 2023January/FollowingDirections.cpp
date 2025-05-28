#include <bits/stdc++.h>

using namespace std;
void dfs(int a, int b, vector<vector<int>>& d, vector<vector<int>>& count, int n){
int i = count[a][b];
int c=a, g=b;
while(a<n&&b<n){
    count[a][b]-=i;
    int da = d[a][b] ==2?1:0;
    int db = d[a][b] ==1?1:0;
    a+=da, b+=db;
}
d[c][g]=(d[c][g]==1?2:1);
while(c<n&&g<n){
    count[c][g]+=i;
    int dc = d[c][g]==2?1:0;
    int dg = d[c][g]==1?1:0;
    c+=dc;
    g+=dg;
}
}
int ans(vector<vector<int>>& d, vector<vector<int>>& count, int n){
    long long int ans = 0;
    for(int i=0; i<n; i++){
        if(d[n-1][i]==2)ans+=1LL*count[n-1][i]*d[n][i];
    }
    for(int i=0; i<n; i++){
        if(d[i][n-1]==1)ans+=1LL*count[i][n-1]*d[i][n];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> count(n,vector<int>(n,1));
    vector<vector<int>> d(n+1, vector<int>(n+1,0));
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            d[i][j]=(s[j]=='R'?1:2);
        }
        cin>>d[i][n];
    }
    for(int i=0; i<n; i++){
        cin>>d[n][i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(d[i][j]==1) if(j<n-1)count[i][j+1]+=count[i][j];
            if(d[i][j]==2) if(i<n-1) count[i+1][j]+=count[i][j];
        }
    }
    long long int start = ans(d, count, n);
    cout<<start<<"\n";
    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        dfs(a,b, d, count, n);
        start = ans(d,count,n);
        cout<<start<<"\n";
    }
}