#include <bits/stdc++.h>
#define int long long
using namespace std;
struct SegTree{
    int n;vector<int> e; 
    SegTree(int a):n(a),e(2*n){}
    void build(){
        for(int i=n-1; i>=1; i--){
            e[i] = e[i*2]+e[i*2+1];
        }
    }
    void upd(int i, int x){
        for(e[i+=n] += x; i>>=1;)e[i] = e[i*2]+e[i*2+1];
    }
    int query(int l, int r){
        int ans=e[r+=n];
        for(l+=n;l<r;l/=2,r/=2){
            if(l&1)ans+=e[l++];
            if(r&1)ans+=e[--r];
        }
        return ans;
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, q;
    cin>>n>>q;
    SegTree seg(n);
    for(int i=0; i<n; i++){
        cin>>seg.e[i+n];
    }
    seg.build();
    for(int i=0; i<q; i++){
        int t, l, j;
        cin>>t>>l>>j;
        if(t==0){
            seg.upd(l,j);
        }else{
            j--;
            cout<<seg.query(l,j)<<"\n";
        }
    }
}