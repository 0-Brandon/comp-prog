#include <bits/stdc++.h>

using namespace std;

struct Segtree{
    vector<int> mi, ma;
    vector<bool> a;
    Segtree(int n):mi(4*n),ma(4*n),a(4*n){}
    int query(){
        return a[0];
    }
    void upd(int i, int dl, int dh, int id, int va){
        if(dl>id||dh<id)return;
        if(dl==id&&dh==dl){
            mi[i] = ma[i] = va;
            a[i] = true;
            return;
        }
        int mid = (dl+dh)/2;
        upd(i*2+1,dl, mid, id, va);
        upd(i*2+2, mid+1, dh, id,va);
        ma[i] = max(ma[i*2+1], ma[i*2+2]);
        mi[i] = min(mi[i*2+1], mi[i*2+2]);
        a[i] = a[i*2+1]&a[i*2+2]&(mi[i*2+2]>ma[i*2+1]);
    }
};
void solve(){
    int n, m, q;
    cin>>n>>m>>q;
    vector<int> x(n),rev(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
        rev[x[i]]=i;
    }
    vector<int> b(m);
    vector<set<int>> ap(n);
    for(int i=0; i<m; i++){
        cin>>b[i];
        b[i]--;
        ap[b[i]].insert(i);
    }
    Segtree seg(n);
    for(int i=0; i<n; i++){
        ap[i].insert(rev[i]+m);//????
        seg.upd(0,0,n-1,rev[i],*ap[i].begin());
    }
    cout<<(seg.query()?"YA":"TIDAK")<<"\n";
    while(q--){
        int i, a;
        cin>>i>>a;i--,a--;
        ap[b[i]].erase(i);
        seg.upd(0,0,n-1,rev[b[i]],*ap[b[i]].begin());
        b[i] = a;
        ap[b[i]].insert(i);
        seg.upd(0,0,n-1,rev[b[i]],*ap[b[i]].begin());
        cout<<(seg.query()?"YA":"TIDAK")<<"\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
