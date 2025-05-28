#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
int dp[505][505][2][4], vis[505][505][2][4];
signed main(){
    int h, w;cin>>h>>w;h++,w++;
    int a, b, c;cin>>a>>b>>c;
    int n;cin>>n;
    vector<int> s(n),t(n);
    queue<pair<int,int>> q;
    vector<vector<int>> dist(h, vector<int>(w,-1));
    auto ok = [&](int x, int y){
        return x<h&&x>=0&&y<w&&y>=0;
    };
    auto mh = [&](int x, int y, int i, int j)->int {
        return abs(x-i)+abs(y-j);
    };
    for(int i=0; i<n; i++){
        cin>>s[i]>>t[i];
        dist[s[i]][t[i]]=0;
        q.push({s[i],t[i]});
    }
    vector visi(h,vector<bool>(w,false));
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if(visi[x][y])continue;
        visi[x][y]=true;
        for(int i=0; i<4; i++){
            if(ok(x+dx[i],y+dy[i])&&dist[x+dx[i]][y+dy[i]]<0){
                dist[x+dx[i]][y+dy[i]]=dist[x][y]+1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            for(int k=0; k<4; k++){
                dp[i][j][0][k]=dp[i][j][1][k]=LLONG_MAX;
            }
        }
    }
    dp[s[0]][t[0]][0][0]=0;
    priority_queue<array<int,5>> pq;
    pq.push({0,s[0],t[0],0,0});
    int ans = LLONG_MAX;
    while(!pq.empty()){
        auto [d,x,y,kick,dir] = pq.top();
        d=-d;
        pq.pop();
        if(vis[x][y][kick][dir])continue;
        vis[x][y][kick][dir]=true;
        ans = min(ans,d+c*mh(x,y,s.back(),t.back()));
        if(kick){
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(ok(nx,ny)&&dp[x][y][1][dir]+a<dp[nx][ny][1][dir]){
                dp[nx][ny][1][dir] = dp[x][y][1][dir]+a;
                pq.push({-dp[nx][ny][1][dir],nx,ny,1,dir});
            }
            if(dp[x][y][1][dir]+c*dist[x][y]<dp[x][y][0][dir]){
                dp[x][y][0][dir] = dp[x][y][1][dir]+c*dist[x][y];
                pq.push({-dp[x][y][0][dir],x,y,0,dir});
            }
        }
        else{
            int dd = (dir+1)%4;
            if(dp[x][y][0][dir]<dp[x][y][0][dd]){
                dp[x][y][0][dd]=dp[x][y][0][dir];
                pq.push({-dp[x][y][0][dd],x,y,0,dd});
            }
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(ok(nx,ny)&&dp[x][y][0][dir]+c<dp[nx][ny][0][dir]){
                dp[nx][ny][0][dir] = dp[x][y][0][dir]+c;
                pq.push({-dp[nx][ny][0][dir],nx,ny,0,dir});
            }
            if(dp[x][y][0][dir]+b<dp[x][y][1][dir]){
                dp[x][y][1][dir] = dp[x][y][0][dir]+b;
                pq.push({-dp[x][y][1][dir],x,y,1,dir});
            }
        }

    }
    cout<<ans<<"\n";
}