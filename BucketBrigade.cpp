#include <bits/stdc++.h>

using namespace std;
vector<int> dx{1,-1,0,0};
vector<int> dy{0,0,1,-1};
int main(){
    freopen("buckets.in","r",stdin);
    freopen("buckets.out","w",stdout);
    int startx,starty;
    vector<vector<char>> x(10,vector<char>(10));
    for(int i=0; i<10; i++){
        string t;
        cin>>t;
        for(int j=0; j<10; j++){
            if(t[j]=='L') {
                startx=i;starty=j;
            }
            x[i][j]=t[j];
        }
    }
    bool done = false;
    vector<vector<bool>> visited(10,vector<bool>(10));
    queue<pair<int,int>> p;
    vector<vector<int>>d(10,vector<int>(10,0));
    p.push({startx,starty});
    while(!p.empty()){
        int i = p.front().first, j=p.front().second;
        p.pop();
        visited[i][j]=true;
        for(int k=0; k<4; k++){
            int t1=i+dx[k];
            int t2=j+dy[k];
            if(t1>=0&&t1<10&&t2>=0&&t2<10&&!visited[t1][t2]&&x[t1][t2]!='R'){
                if(x[t1][t2]=='B'){
                    cout<<d[i][j];
                    done = true;
                }
                d[t1][t2]=d[i][j]+1;
                p.push({t1,t2});
            }
        }
        if(done) break;
    }
}