#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, q;
    cin>>n>>q;
    vector<vector<pair<int,int>>> res(n);
    for(int i=0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        res[--a].push_back({--b,c});
        res[b].push_back({a,c});
    }
    vector<vector<int>> ans(32,vector<int>(n,1));
    for(int b=0; b<=31; b++){
        for(int i=0; i<n; i++){
            for(auto [o,c]:res[i]){
                c = (c>>b)&1;
                if(c==0)ans[b][i]=0,ans[b][o]=0;
            }
        }
        for(int i=0; i<n; i++){
            ans[b][i]=0;
            for(auto& [o,c]:res[i]){
                if((c>>b)&1==1&&ans[b][o]==0)ans[b][i]=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        int cur = 0;
        for(int j=0; j<=31; j++){
            cur +=ans[j][i]<<j;
        }
        cout<<cur<<" ";
    }
    cout<<"\n";
}