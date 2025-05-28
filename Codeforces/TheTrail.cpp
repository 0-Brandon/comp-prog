#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector a(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)cin>>a[i][j];
    }
    int x=0,y=0;
    for(int t=0; t<n+m-2; t++){
        if(s[t]=='D'){
            int su = 0;
            for(int i=0; i<m; i++)su+=a[x][i];
            a[x][y] = -su;
            x++;
        }
        else{
            int su = 0;
            for(int i=0; i<n; i++)su+=a[i][y];
            a[x][y]=-su;
            y++;
        }
    }
    int su = 0;
    for(int i=0; i<n; i++)su+=a[i][m-1];
    a[n-1][m-1] = -su;
    for(auto& i:a){
        for(auto& j:i)cout<<j<<" ";
        cout<<"\n";
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}