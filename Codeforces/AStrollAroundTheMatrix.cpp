#include <bits/stdc++.h>
#define int long long
using namespace std;

struct info{
    int mi, ma, len, su, tot;
    info operator+(info b){
        info c;
        c.mi = min(mi,b.mi);
        c.ma = max(ma,b.ma);
        c.len = b.len+len;
        c.su = su+b.su;
        c.tot = tot+b.tot+len*b.su;
        return c;
    }
};
struct Segtree{
    vector<info> e;
    vector<int> tag;
    Segtree(int n):e(4*n),tag(4*n){build(1,0,n-1);}
    void build(int i, int dl, int dh){
        if(dl+1==dh){
            e[i] = {0,0,1,0,0};
            return;
        }
        int mid = (dl+dh)/2;
        build(i*2,dl,mid);
        build(i*2+1,mid,dh);
        e[i]=e[i*2]+e[i*2+1];
    }
    void add(int i, int v){
        tag[i]+=v;
        e[i].mi += v;
        e[i].ma += v;
        e[i].su += v * e[i].len;
        e[i].tot += v * e[i].len * (e[i].len - 1) / 2;
    }
    void push(int i){
        if(tag[i]==0)return;
        add(i*2,tag[i]);
        add(i*2+1,tag[i]);
        tag[i] = 0;
    }
    int getid(int i, int dl, int dh, int v){ //get first index greater than v
        if(e[i].mi>v){
            return 0;
        }
        if(e[i].ma<=v){
            return e[i].len;
        }
        int mid = (dl+dh)/2;
        push(i);
        return getid(i*2,dl,mid,v)+getid(i*2+1,mid,dh,v);
    }
    void upd(int i, int dl, int dh, int id, int v){ //suffix add
        if(dh<=id) return;
        if(dl>=id) {
            add(i,v);
            return;
        }
        push(i);
        int mid = (dl+dh)/2;
        upd(i*2,dl,mid,id,v);
        upd(i*2+1,mid,dh,id,v);
        e[i] = e[i*2]+e[i*2+1];
    }
    info query(int i, int dl, int dh, int l, int r){
        if(dh<=l||dl>=r) return {0,0,0,0,0};
        if(dl>=l&&dh<=r) return e[i];
        int mid = (dl+dh)/2;
        push(i);
        return query(i*2,dl,mid,l,r)+query(i*2+1,mid,dh,l,r);
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> a(n),b(m);
    vector<int> da(n),db(m);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<m; i++)cin>>b[i];
    int sta = a[0];
    int stb = b[0];
    for(int i=0; i<n-1; i++)da[i] = a[i+1]-a[i];
    for(int i=0; i<m-1; i++)db[i] = b[i+1]-b[i];
    Segtree seg(m);
    int l = 0;
    for(int i=0; i<m-1; i++){
        seg.upd(1,0,m-1,i,db[i]-l);
        l = db[i];
    }
    while(q--){
        int t, k, d;
        cin>>t>>k>>d;
        if(t==1){
            if(k==n){
                sta+=d;
                k--;  
            }
            for(int i=n-1-k; i<n-1; i++){
                da[i] += d;
            }
        }
        else{
            if(k==m){
                stb+=d;
                k--;
            }
            seg.upd(1,0,m-1,m-1-k,d);
        }
        int ans = sta+stb;
        ans*=(n+m-1);
        int last=0;
        for(int i=0; i<n-1; i++){
            int id = seg.getid(1,0,m-1,da[i]);
            info cur = seg.query(1,0,m-1,last,id);
            ans+=da[i]*(n-1+m-1-(i+id)); //this difference will affect all indices on our path after
            ans+=cur.su*(n-1+m-1-(i+last))-cur.tot; //this dif will also affect all indices on our path after, but we have to remove the rest of the sum
            last = id;
        }
        info rest = seg.query(1,0,m-1,last,m-1);
        ans+=rest.su*(n-1+m-1-(n-1+last))-rest.tot;
        cout<<ans<<"\n";
    }
}
