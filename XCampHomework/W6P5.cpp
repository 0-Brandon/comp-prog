#include <bits/stdc++.h>

using namespace std;
struct DSU{
    vector<int> e;
    DSU(int n):e(n,-1){}
    int par(int a) {return e[a]<0?a:e[a]=par(e[a]);}
    int get(int a){return -e[par(a)];}
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
    int n;
    cin>>n;
    DSU o(n),z(n);
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        if(c==0)z.merge(a,b);
        else o.merge(a,b);
    }
    long long int ans = 0;
    for(int i=0; i<n; i++){
        if(o.par(i)==i)ans+=1LL*o.get(i)*(o.get(i)-1);
        if(z.par(i)==i)ans+=1LL*z.get(i)*(z.get(i)-1);
        ans+=1LL*(z.get(i)-1)*(o.get(i)-1);
    }
    cout<<ans<<"\n";
}