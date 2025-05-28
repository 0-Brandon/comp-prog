#include <bits/stdc++.h>

using namespace std;
constexpr int mm = 2e6+1;
struct segtree{
    int n;vector<int> m,l,r,al;
    void pull(int i){
        m[i] = max({m[i*2+1],m[i*2+2],r[i*2+1]+l[i*2+2]});
        if(al[i*2+1])l[i] = m[i*2+1]+l[i*2+2];
        else l[i] = l[i*2+1];
        if(al[i*2+2])r[i] = m[i*2+2]+r[i*2+1];
        else r[i] = r[i*2+2];
        al[i] = al[i*2+2]&al[i*2+1];
    }
    segtree(int a):n(a),m(4*n),l(4*n),r(4*n),al(4*n){build(0,0,mm);}
    void build(int i, int dl, int dh){
        int mid = (dl+dh)/2;
        if(dl==dh)m[i]=l[i]=r[i]=al[i]=1;
        else{
            build(i*2+1,dl,mid);
            build(i*2+2,mid+1,dh);
            pull(i);
        }
    }
    int query(int k){
        if(m[0]<k)return n-r[0];
        return query(0,0,mm,k);
    }
    int query(int i, int dl, int dh, int k){
        int mid = dl+(dh-dl)/2;
        if(i*2+1>m.size()){return dl;}
        if(m[i*2+1]>=k)return query(i*2+1,dl,mid,k);
        else if(r[i*2+1]+l[i*2+2]>=k)return mid-r[i*2+1]+1;
        return query(i*2+2,mid+1,dh,k);
    }
    void upd(int i, int dl, int dh, int id, int a){
        if(dl==dh&&dl==id){m[i]=l[i]=r[i]=al[i]=a;return;}
        if(dl>id||dh<id)return;
        int mid = (dl+dh)/2;
        upd(i*2+1, dl, mid, id, a);
        upd(i*2+2, mid+1, dh, id,a);
        pull(i);
    }
}seg(mm-951429);
void solve(){
    int n;cin>>n;
    set<int> s;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        seg.upd(0,0,mm,a,0);
        s.insert(a);
    }
    seg.upd(0,0,mm,0,0);
    int q;
    cin>>q;
    while(q--){
        char t;cin>>t;
        int a;cin>>a;
        if(t=='+'){
            seg.upd(0,0,mm,a,0);
            s.insert(a);
        }
        if(t=='-'){
            seg.upd(0,0,mm,a,1);
            s.erase(a);
        }
        if(t=='?'){
            cout<<seg.query(a)<<" ";
        }
    }
    cout<<"\n";
    for(auto& i:s)seg.upd(0,0,mm,i,1);
}
int main(){
    new(&seg) segtree(mm+1);
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}