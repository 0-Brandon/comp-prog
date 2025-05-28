#include <bits/stdc++.h>
#define int long long
using namespace std;


signed main(){
    int n, m;cin>>n>>m;
    vector<int> x(1<<m,0);
    int ans = 0;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        if(x[t])ans+=t;
        x[t] = t;
    }
    vector<int> e(1<<m,-1);
    auto par = [&](auto&& par, int i)-> int {
        return e[i]<0?i:e[i] = par(par, e[i]);
    };
    auto merge = [&](int i, int j, int a){
        i = par(par, i),j=par(par, j);
        if(i==j)return;
        if(e[i]>e[j])swap(i,j);
        e[i]+=e[j];
        e[j] = i;
        ans+=a;
    };
    for(int i=(1<<m)-1; i>=0; i--){
        for(int j=0; j<m&&!x[i]; j++){
            x[i] = x[i|(1<<j)];
        }
        //find first element in layer above that exists
        //for every element in the layer above that exists, their pairwise and is guaranteed to be i
        //thus, if they are not connected, we should connect them and get i
        for(int j=0; j<m; j++){
            if(!x[i|(1<<j)])continue;
            merge(x[i],x[i|(1<<j)], i);
        }
    }
    cout<<ans<<"\n";
}