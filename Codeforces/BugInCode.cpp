#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, p; cin>>n>>p;
    vector<vector<int>> adj(n);
    vector<pair<int,int>> cnt(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;a--,b--;
        cnt[i].second = i;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cnt[a].first++;
        cnt[b].first++;
    }
    int ans = 0;
    sort(cnt.begin(),cnt.end());
    //outer loop is o(n)
    for(auto& [nu, i]:cnt){
        //log n
        int init=distance(lower_bound(cnt.begin(),cnt.end(), make_pair(p-nu,-100LL)), cnt.end());
        if(nu+nu>=p)init--;
        map<int,int> dup;
        //we process each edge 2 times, so its 2n total
        for(auto& c:adj[i])dup[c]++;
        for(auto&[node,num]:dup){
            if(nu+adj[node].size()>=p&&nu+adj[node].size()-num<p){
                ans--;
                if(init==0)break;
            }
        }
        ans+=init;
    }
    
    cout<<ans/2<<"\n";
}