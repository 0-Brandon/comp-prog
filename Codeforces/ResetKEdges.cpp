#include <bits/stdc++.h>

using namespace std;
int n, k;
vector<int> st, head, depth;
vector<bool> r;
vector<vector<int>> adj;
void prep(int i, int h){
    st.push_back(i);
    if(st.size()>=h){
        head[i]=st[st.size()-h];
    }
    for(auto& c:adj[i]){
        prep(c,h);
    }
    st.pop_back();
}
void dfs(int i){
    r[i]=true;
    for(auto& c:adj[i])if(!r[c])dfs(c);
}
bool ok(int h){
    st.clear();
    head.assign(n,-1);
    depth.assign(n,-1);
    depth[0]=0;
    prep(0,h);

    r.assign(n,0);
    vector<int> ord;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        ord.push_back(cur);
        for(auto& i:adj[cur]){
            q.push(i);
            depth[i]=depth[cur]+1;
        }
    }
    int res=0;
    reverse(ord.begin(),ord.end());
    for(auto& i:ord){
        if(!r[i]&&depth[i]>h){
            res++;
            dfs(head[i]);
        }
    }
    return res<=k;
}
void solve(){
    cin>>n>>k;
    adj.assign(n,vector<int>());
    for(int i=1; i<n; i++){
        int a;cin>>a; a--;
        adj[a].push_back(i);
    }
    int low=1, high=n;
    while(low<high){
        int mid = low+(high-low)/2;
        if(ok(mid)){
            high = mid;
        }else{
            low=mid+1;
        }
    }
    cout<<low<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}