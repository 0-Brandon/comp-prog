#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m, k;cin>>n>>m>>k;
    k-=m;
    int a,b,c;cin>>a>>b>>c;
    int t;cin>>t;
    vector<int> x(m);
    for(int i=0; i<m; i++){
        cin>>x[i];
    }
    int ans = -1;
    vector<int> p(m-1);
    priority_queue<pair<int,int>> pq;
    //num added, station
    for(int i=0; i<m-1; i++){
        if(b*(x[i]-1)>t)break;
        int u = min(x[i+1]-1, x[i]+(t-b*(x[i]-1))/a);
        ans+=u-x[i]+1;
        p[i] = u+1;
        if(p[i]<x[i+1]&&b*(x[i]-1)+(p[i]-x[i])*c<=t){
            pq.push({min(x[i+1]-1,p[i]+(t-b*(x[i]-1)-(p[i]-x[i])*c)/a)-p[i]+1,i});
        }
    }
    while(k--){
        if(pq.empty())break;
        auto[va,i] = pq.top();
        pq.pop();
        ans+=va;
        int u = min(x[i+1], p[i]+va);
        p[i] = u;
        if(p[i]<x[i+1]&&b*(x[i]-1)+(p[i]-x[i])*c<=t){
            pq.push({min(x[i+1]-1,p[i]+(t-b*(x[i]-1)-(p[i]-x[i])*c)/a)-p[i]+1,i});
        }
    }
    if(b*(n-1)<=t)ans++;
    cout<<ans<<"\n";
}