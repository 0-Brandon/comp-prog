#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    map<int,int> x;
    vector<int> s(m),d(m);
    for(int i=0; i<n; i++){
        int a;cin>>a;
        x[a]++;
    }
    for(int i=0; i<m; i++)cin>>s[i];
    for(int i=0; i<m; i++)cin>>d[i];
    priority_queue<pair<int,int>> pq;
    vector<vector<int>> ans(m);
    for(auto& i:x)pq.push({i.second,i.first});
    queue<vector<int>> wait;
    for(int i=0; i<m; i++){
        for(int j=0; j<s[i]; j++){
            if(wait.size()&&j-wait.front()[2]>=d[i]){
                if(wait.size())pq.push({wait.front()[0],wait.front()[1]});
                if(wait.size())wait.pop();
            }
            if(pq.empty()){cout<<"-1\n";return;}
            auto [num, id] = pq.top();
            pq.pop();
            ans[i].push_back(id);
            if(--num>0)wait.push({num,id,j});
        }
        while(wait.size()){
            pq.push({wait.front()[0],wait.front()[1]});
            wait.pop();
        }
    }
    for(auto& i:ans){
        for(int j=0; j<i.size(); j++){
            cout<<i[j]<<" \n"[j==i.size()-1];
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}