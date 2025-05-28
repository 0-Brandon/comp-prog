#include <bits/stdc++.h>

using namespace std;

constexpr int LOG = 18;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    vector<pair<int,int>> x;
    vector<vector<pair<int,int>>> m(n+5,vector<pair<int,int>>(LOG,{INT_MAX, -1}));
    vector<int> t;
    for(int i=0; i<n; i++){
        int s, e;cin>>s>>e;
        x.push_back({s,e});
        t.push_back(e);
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    for(int i=0; i<n; i++){
        int id = lower_bound(t.begin(),t.end(),x[i].second)-t.begin();
        m[id][0] = min(m[id][0], {x[i].first,i});
    }
    for(int j=1; j<LOG; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            m[i][j] = min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
        }
    }
    //i j i j
    vector<vector<int>> up(n,vector<int>(LOG));
    for(int i=0; i<n; i++){
        int s = lower_bound(t.begin(),t.end(),x[i].first)-t.begin();
        int e = lower_bound(t.begin(),t.end(), x[i].second)-t.begin();
        int l = 31-__builtin_clz(e-s);
        up[i][0] = min(m[s][l],m[e-(1<<l)+1][l]).second;
    }
    for(int j=1; j<LOG; j++){
        for(int i=0; i<n; i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    while(q--){
        int s, e;cin>>s>>e;s--,e--;
        if(x[e].first<=x[s].second&&x[e].second>=x[s].second){
            if(s==e)cout<<"0\n";
            else cout<<"1\n";
            continue;
        }
        int ans = 0;
        for(int j=LOG-1; j>=0; j--){
            if(x[up[e][j]].first>x[s].second)e = up[e][j], ans+=1<<j;
        }
        e = up[e][0];
        ans+=1;
        if(x[e].first<=x[s].second&&x[e].second>=x[s].second){
            if(e!=s)ans++;
            cout<<ans<<"\n";
        }
        else{
            cout<<"impossible\n";
        }
    }
}