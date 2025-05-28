#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m, k;
    cin>>n>>m>>k;
    vector g(n,vector<int>(m,0));
    vector b(n,vector<int>(m,0));
    vector<int> dx{0,0,1,-1},dy{1,-1,0,0};
    int sx,sy;
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        if(i==0)sx=a,sy=b;
        g[a][b] = k-i-1;
    }
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<m; j++)b[i][j] = (s[j]=='#');
    }
    vector vis(n,vector<bool>(m));
    vector<vector<pair<int,int>>> q(3005*3005+1);
    q[0].push_back({sx,sy});
    unsigned long long ans = 0;
    vis[sx][sy]=true;
    for(int d=0;d<=3005*3005; d++){
        for(auto& [x,y]:q[d]){
            ans+=1LL*d*d;
            for(int j=0; j<4; j++){
                int nx = x+dx[j], ny=y+dy[j];
                if(nx<0||nx==n||ny<0||ny==m||vis[nx][ny]||b[nx][ny])continue;
                q[max(g[nx][ny],d)+1].push_back({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
    cout<<ans<<"\n";
}