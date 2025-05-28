#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct FT{
    vector<ll> e;
    FT(int n, int c):e(n,0){for(int i=0; i<n; i++)update(i,c);}
    void update(int i, int dif){
        for(;i<e.size(); i|=(i+1))e[i]+=dif;
    }
    int query(int j, int i){
        ll ans=0;
        for(; i>0; i&=(i-1))ans+=e[i-1];
        return ans;
    }
};

struct SegTree{
    int n, icl=0;//inclusive on right border?
    vector<ll> e;
    SegTree(vector<int>&& a):n(a.size()),e(2*n){
        for(int i=n; i<2*n; i++)e[i]=a[i-n];
        for(int i=n-1; i>=1; i--)e[i]=e[i*2]+e[i*2+1];
    }
    void update(int i, int dif){
        for(e[i+=n]+=dif; i>>=1;){e[i]=e[i*2]+e[i*2+1];}
    }
    int query(int l, int r){
        ll ans = icl*e[r+n];
        for(l+=n,r+=n; l<r; l>>=1,r>>=1){
            if(l&1){ans+=e[l++];}
            if(r&1){ans+=e[--r];}
        }
        return ans;
    }
};

int main(){
    freopen("haircut.in","r",stdin);
    freopen("haircut.out","w",stdout);
    int n;
    cin>>n;
    vector<int> x(n);
    map<int,vector<int>> mp;
    for(int i=0; i<n; i++){
        cin>>x[i];
        mp[x[i]].push_back(i);
    }
    ll ans=0;
    FT ft(n,1);
   //SegTree ft(vector<int>(n,1));
    for(int i=0; i<n; i++){
        cout<<ans<<"\n";
        for(auto& j:mp[i]){
            ft.update(j,-1);
            ans+=ft.query(0,j);
        }
    }
}