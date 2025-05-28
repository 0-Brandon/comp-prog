make observation
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    int ans = INT_MAX;
    vector<int> p(n), c(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
        p[i]--;
    }
    for(int i=0; i<n; i++){
        cin>>c[i];
    }
    vector<bool> visited(n);
    auto check = [&](int k, int m,vector<int>& x){
        vector<bool> vis(m);
        for(int i=0; i<m; i++){
            if(!vis[i]){
                int l = (i+k)%m;
                vis[i]= true;
                bool f = true;
                while(l!=i){
                    vis[l]=true;
                    if(c[x[i]]!=c[x[l]])f=false;
                    l = (l+k)%m;
                }
                if(f)return true;
            }
        }
        return false;
    };
    auto w = [&](int i){
        int l = p[i];
        visited[i]= true;
        vector<int> cycle;
        while(l!=i){
            cycle.push_back(l);
            visited[l]=true;
            l = p[l];
        }
        cycle.push_back(i);
        int m = cycle.size();
        for(int j=1; j<=m; j++){
            if(m%j==0){
                if(check(j,m,cycle))ans = min(ans,j);
            }
        }
    };
    for(int i=0; i<n; i++){
        if(!visited[i]){
            w(i);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}