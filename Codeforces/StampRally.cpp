#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;cin>>n>>m;
    vector<pair<int,int>> edges;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        edges.push_back({a,b});
    }
    int q;cin>>q;
    vector<array<int,3>> queries;
    for(int i=0; i<q; i++){
        int a, b,c;cin>>a>>b>>c;a--,b--;
        queries.push_back({a,b,c});
    }
    vector<int> l(q,0);
    vector<int> h(q,m-1);
    vector<int> dsu(n);
    auto par = [&](auto&& par, int i)->int {return (dsu[i]<0)?(i):(dsu[i] = par(par, dsu[i]));};
    auto merge =[&](int i, int j){
        i=par(par,i),j=par(par,j);
        if(i==j)return;
        if(dsu[i]>dsu[j])swap(i,j);
        dsu[i]+=dsu[j];
        dsu[j]=i;
    };
    for(int t=0; t<31-__builtin_clz(m)+1; t++){
        vector<vector<int>> mid(q);
        for(int i=0; i<q; i++){
            mid[(l[i]+h[i])/2].push_back(i);
        }
        dsu.assign(n,-1);
        for(int j=0; j<m; j++){
            merge(edges[j].first,edges[j].second);
            for(auto& qu:mid[j]){
                int ch = -dsu[par(par,queries[qu][0])];
                if(par(par,queries[qu][0])!=par(par,queries[qu][1]))ch+=-dsu[par(par,queries[qu][1])];
                if(ch>=queries[qu][2]){
                    h[qu] = j;
                }
                else{
                    l[qu]=j+1;
                }
            }
        }
    }
    for(int i=0; i<q; i++){
        cout<<l[i]+1<<"\n";
    }
}