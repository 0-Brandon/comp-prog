#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 61;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    vector<int> x(n);
    vector<vector<int>> b(M);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        x[i]=a;
        for(int j=0; j<M; j++){
            if(!((a>>j)&1LL))b[j].push_back(i);
        }
    }
    while(q--){
        int k;
        cin>>k;
        int ans = 0;
        vector<bool> o(n,false);
        for(int bi=M-1; bi>=0; bi--){
            int c = 0;
            for(auto& i:b[bi]){
                if(o[i])continue;
                c+=(1LL<<bi)-(x[i]&((1LL<<bi)-1));
                if(c>k)break;
            }
            for(int i=0; i<n; i++){
                if(c>k)break;
                if(o[i]){
                    c+=(1LL<<bi);
                }
            }
            if(c<=k){
                k-=c;
                ans|=(1LL<<bi);
                for(auto& i:b[bi])o[i]=true;
            }
        }
        cout<<ans<<"\n";
    }
}