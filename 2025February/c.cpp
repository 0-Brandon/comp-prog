#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    vector<int> adj(n,0);
    for(int i=0;i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        adj[a]|=(1<<b);
        adj[b]|=(1<<a);
    }
    int ans = 2e9;
    for(int mask = 0; mask<(1<<n); mask++){
        int sz = __builtin_popcount(mask);
        int in = 0;
        int out = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((adj[i]>>j)&1){
                    if(((mask>>i)&1)&&((mask>>j)&1))in++;
                    if((!((mask>>i)&1))&&!((mask>>j)&1))out++;
                }
            }
        }
        int iadd = sz*(sz-1)/2-in;
        int oadd = 0;
        for(int i=0; i<n; i++){
            if(!((mask>>i)&1)){   
                oadd+=sz-__builtin_popcount(adj[i]&mask);
            }
        }
        ans = min(ans,iadd+oadd+out);
       // cout<<bitset<4>(mask)<<" "<<iadd<<" "<<oadd<<" "<<out<<"\n";
    }
    cout<<ans<<"\n";
}