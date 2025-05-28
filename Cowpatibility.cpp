#include <bits/stdc++.h>
//Completely wrong lol
using namespace std;

int n;
struct DSU{
    vector<int> e, comp;
    DSU(int a):e(a,-1){for(int i=n+1; i<a; i++)e[i]=0;}
    int par(int a){return (e[a]<=0 )? (a) : (e[a]=par(e[a]));}
    bool merge(int a, int b){
        a=par(a),b=par(b);
        if(a==b)return false;
        if(e[a]>e[b])swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        return true;
    }
};
int main(){
    cin>>n;
    DSU dsu(n+1e6+5);
    for(int i=0; i<n; i++){
        for(int i=0; i<5; i++){
            int a;
            cin>>a;
            a+=n;
            dsu.merge(a,i+1);
        }
    }
    vector<int> x;
    for(int i=0; i<n+1e6+5; i++)if(dsu.par(i)==i&&-dsu.e[i]!=0){
        x.push_back(-dsu.e[i]);
        cout<<i<<" "<<-dsu.e[i]<<"\n";
    }
    int ans = 0;
    int cur = 0;
    for(int i=0; i<x.size(); i++){
        ans+=x[i]*cur;
        cur+=x[i];
    }
    cout<<ans<<"\n";
}