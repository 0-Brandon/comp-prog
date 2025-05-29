#include <bits/stdc++.h>

using namespace std;

struct DSU{
    vector<int> e;
    DSU(int i):e(i){}
    int par(int i){
        return e[i]<0?i:e[i] = par(e[i]);
    }
    bool merge(int a, int b){
        a = par(a),b=par(b);
        if(a==b)return false;
        if(e[a]>e[b])swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        return true;
    }
};
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> ed;
    DSU dsu(n);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        if(!dsu.merge(a,b)){
            ed.push_back({a,b});
        }
    }
    vector<int> x;
    for(int i=0; i<n; i++)if(dsu.par(i)==i)x.push_back(i);
    cout<<x.size()<<"\n";
    assert(x.size()==ed.size());
    for(int i=0; i<x.size()-1; i++){
        cout<<ed[i].first<<" "<<ed[i].second<<" "<<x[i]<<" "<<x[i+1]<<"\n";
    }
}