#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, h, r;
    cin>>n>>h>>r;
    vector<array<int,3>> x(n);
    vector<bool> d(n);
    set<int> s;
    queue<int> q;
    for(int i=0; i<n; i++)s.insert(i);
    for(int i=0; i<n; i++){
        cin>>x[i][0]>>x[i][1]>>x[i][2];
        if(h-x[i][2]<=r)d[i]=true;
        if(x[i][2]<=r){q.push(i);s.erase(i);}
    }
    auto dist = [&](int i, int j){return (x[j][0]-x[i][0])*(x[j][0]-x[i][0])+
                                            (x[j][1]-x[i][1])*(x[j][1]-x[i][1])+
                                            (x[j][2]-x[i][2])*(x[j][2]-x[i][2]);};
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(d[cur]){cout<<"Yes\n";return;}
        vector<int> rev;
        for(auto& i:s){
            if(dist(i,cur)<=4*r*r){
                q.push(i);rev.push_back(i);
            }
        }
        for(auto& i:rev)s.erase(i);
    }
    cout<<"No\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();   
}