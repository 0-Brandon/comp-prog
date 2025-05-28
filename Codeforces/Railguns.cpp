#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<bool>> visited(n+1,vector<bool>(m+1,false));
    int r;
    cin>>r;
    vector<pair<int,pair<int,int>>> shots;
    for(int i=0; i<r; i++){
        int time, dir, cord;
        cin>>time>>dir>>cord;
        shots.push_back({time, {cord, dir}});
    }
    sort(shots.begin(),shots.end());
    visited[0][0]=true;
    int p=0;
    for(int t=1; t<1000000; t++){
        bool f=false;
        for(int i=n; i>=0; i--){
            for(int j=m; j>=0; j--){
                if(!visited[i][j])continue;
                f=true;
                if(i<n)visited[i+1][j]=true;
                if(j<m)visited[i][j+1]=true;
            }
        }
        if(!f){cout<<"-1\n";return;}
        while(p<r && (shots[p].first==t)){
            auto[c,d]=shots[p].second;
            if(d==1){
                for(int i=0; i<=m; i++){
                    visited[c][i]=false;
                }
            }else{
                for(int i=0; i<=n; i++){
                    visited[i][c]=false;
                }
            }
            p++;
        }
        if(visited[n][m]){
            cout<<t<<"\n";
            return;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}