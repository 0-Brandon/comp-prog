#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Segtree{
    vector<int> e,lazy;
    Segtree(int n):e(4*n,0), lazy(4*n,0){}
    void push(int i, int dl, int dh){
        e[i]+=(dh-dl+1)*lazy[i]; 
        if(dl!=dh){
            lazy[i*2+1]+=lazy[i];
            lazy[i*2+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    int query(int id, int dl, int dh, int l, int h){
        push(id,dl,dh);
        if(dl>h||dh<l)return 0;
        if(dl>=l&&dh<=h)return e[id];
        int mid = (dl+dh)/2;
        return query(id*2+1,dl,mid,l,h)+query(id*2+2,mid+1,dh,l,h); 
    }
    void update(int id, int dl, int dh, int l, int h, int a){
        push(id,dl,dh);
        if(dl>h||dh<l)return;
        if(l<=dl&&h>=dh){
            lazy[id] = a; push(id,dl,dh);
            return;
        }
        int mid = (dl+dh)/2;
        update(id*2+1,dl,mid,l,h,a);
        update(id*2+2,mid+1,dh,l,h,a);
        e[id] = e[id*2+1]+e[id*2+2];
    }
};
void solve(){
    int n, c;
    cin>>n>>c;
    Segtree seg(n);
    for(int i=0; i<c; i++){
        int t;
        cin>>t;
        if(t==0){
            int a, b, c;cin>>a>>b>>c;a--,b--;
            seg.update(0,0,n-1,a,b,c);
        }else{
            int a, b;cin>>a>>b;a--,b--;
            cout<<seg.query(0,0,n-1,a,b)<<"\n";
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}