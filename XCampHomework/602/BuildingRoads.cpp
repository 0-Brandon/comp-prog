#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int n):e(n,-1){}
    int par(int i){
        return e[i]<0?i:e[i]=par(e[i]);
    }
    bool merge(int a, int b){
        a=par(a),b=par(b);
        if(a==b)return false;
        if(e[a]>e[b])swap(a,b);
        e[a]+=e[b];
        e[b] = a;
        return true;
    }
};
int main(){
    int n, m, q;
    cin>>n>>m>>q;n++;
    vector<vector<pair<int,int>>> edges(m+1);
    for(int i=1; i<=m; i++){
        for(int j=i*2; j<n; j+=i){
            edges[i].push_back({j,j-i});
        }
    }
    vector<pair<int,int>> qe(q);
    for(int i=0; i<q; i++)cin>>qe[i].first>>qe[i].second;
    vector<int> l(q,0),h(q,m);
    for(int t=0; t<20; t++){
        vector<vector<int>> mid(m+1);
        for(int i=0; i<q; i++){
            mid[(l[i]+h[i]+1)/2].push_back(i);
        }
        DSU dsu(n);
        for(int i=m; i>=1; i--){
            for(auto&[a,b]:edges[i]){
                dsu.merge(a,b);
            }
            for(auto& j:mid[i]){
                if(dsu.par(qe[j].first)==dsu.par(qe[j].second)){
                    l[j] = i;
                }else{
                    h[j] = i-1;
                }
            }
        }
    }
    for(auto& i:l)cout<<m-i+1<<"\n";
}