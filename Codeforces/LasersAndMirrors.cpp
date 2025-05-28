#include <bits/stdc++.h>
//not working
using namespace std;
int idx= 0;
struct point{
    int x, y,id;
    point(a,b):x(a),y(b),id(idx++){}
    bool operator==(point p){
        return p.x==x&&p.y==y;
    }
};
//0 is going down, 2 is going up, 1 is going left, 3 is going right
int main(){
    int n, a, b, c, d;
    cin>>n>>a>>b>>c>>d;
    point start(a,b);
    vector<vector<point>> x(2,vector<point>());
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x[0].push_back({a,b});
        x[1].push_back({a,b});
    }
    point barn(c,d);
    vector<int> dist(n+2);
    sort(x[0].begin(),x[0].end(),[&](point a, point b){return (a.x<b.x)?true:(a.y<b.y);});
    sort(x[1].begin(),x[1].end(),[&](point a, point b){return (a.y<b.y)?true:(a.x<b.x);});
    
    //do we need to keep track of distance in the queue? 
    //perhaps we can do 2 dimensional dist array for shortest dist to node x so that laser enters it going in a certain direction
    deque<pair<point,int>> q;
    dist[0]=0;
    for(int i=0; i<4; i++)q.push_back({start,i});
    while(!q.empty()){
        auto[cur,dir] = q.front();
        q.pop_front();
        //odd means going leftright
        bool di = dir&1;
        point du(-1,-1),dd(-1,-1),sa(-1,-1);
        int i = distance(x[!di],begin(),lower_bound(x[!di].begin(),x[!di].end(),cur));
        if(i+1<x[0].size())du = x[!di][i+1];
        if(i-1>=0)dd = x[!di][i-1];
        i = distance(x[di].begin(),lower_bound(x[di].begin(),x[di].end(),cur));
        if(i+1<x[0].size())sa =x[di][i+1];

        if(di){
            //leftright
            if(dd.y==cur.y&&dist[dd.id]>dist[cur.id]+1)dist[dd.id]=dist[cur.id]+1,q.push_back({dd,0});
            if(du.y==cur.y&&dist[du.id]>dist[cur.id]+1)dist[du.id]=dist[cur.id]+1,q.push_back({du,2});
            if(sa.x==cur.x&&dist[sa.id]>dist[cur.id])dist[as.id]=dist[cur],q.push_front({sa,dir});
        }else{
            //updown
            if(dd.x==cur.x&&dist[dd.id]>dist[cur.id]+1)dist[dd.id]=dist[cur.id]+1,q.push_back({dd,3});
            if(du.x==cur.x&&dist[du.id]>dist[cur.id]+1)dist[du.id]=dist[cur.id]+1,q.push_back({du,1});
            if(sa.y==cur.y&&dist[sa.id]>dist[cur.id])dist[as.id]=dist[cur],q.push_front({sa,dir});
        }
    }
    cout<<dist.back()<<"\n";
}