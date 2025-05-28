#include <bits/stdc++.h>
#define int long long
using namespace std;

struct DSU{
    vector<int> e;
    int cnt =0;
    DSU(int n):e(n,-1){};
    void add(){cnt++;}
    int par(int i){return e[i]<0?i:e[i]=par(e[i]);}
    bool merge(int a, int b){
        a=par(a),b=par(b);
        if(a==b)return false;
        if(e[a]>e[b])swap(a,b);
        e[a]+=e[b];
        e[b]=a;
        cnt--;
        return true;
    }
};
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<vector<int>> pos(1e5+1);
    int m=0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        m=max(m,x[i]);
        pos[x[i]].push_back(i);
    }
    DSU dsu(n);
    vector<int> ord;
    for(int i=m; i>0; i--){
        for(auto& j:pos[i]){
            dsu.add();
            if(j-1>=0&&x[j-1]>=i)dsu.merge(j,j-1);
            if(j+1<n&&x[j+1]>=i)dsu.merge(j,j+1);
        }
        ord.push_back(dsu.cnt);
    }
    reverse(ord.begin(),ord.end());
    for(int s=1; s<=m; s++){
        int ans = 0;
        for(int i=0; i<ord.size(); i+=s){
            ans+=ord[i];
        }
        cout<<ans<<" ";
    }
}