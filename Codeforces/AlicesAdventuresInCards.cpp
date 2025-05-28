#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int>> x(3,vector<int>(n+1));
    vector<int> m(3,n);
    for(int j=0; j<3; j++)for(int i=1; i<=n; i++){
        cin>>x[j][i];
    }
    vector<bool> pos(n,0);
    pos[n] = true;
    vector<pair<int,int>> trace(n+1), ans;
    trace[n] = make_pair(-1,-1);
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<3; j++){
            if(x[j][i]>x[j][m[j]]){
                pos[i] = true;
                trace[i] = make_pair(j,m[j]);
                for(int k=0; k<3; k++){
                    if(x[k][m[k]]>x[k][i])m[k] = i;
                }
            }
        }
    }
    if(!pos[1])cout<<"NO\n";
    else{
        vector op{'q','k','j'};
        cout<<"YES\n";
        int i = 1;
        while(trace[i].first!=-1){
            auto [j,k] = trace[i];
            ans.push_back({j,k});
            i = k;
        }
        cout<<ans.size()<<"\n";
        for(auto[i,j]:ans)cout<<op[i]<<" "<<j<<"\n";
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}