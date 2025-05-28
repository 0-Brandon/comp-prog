#include <bits/stdc++.h>

using namespace std;

struct SegTree{
    int n;
    vector<int> e;
    SegTree(vector<int> a):n(a.size()),e(2*a.size()){
        for(int i=n; i<2*n; i++){
            e[i]=a[i-n];
        }
        for(int i=n-1; i>0; i--){
            e[i] = e[i*2]+e[i*2+1];
        }
    }
    void upd(int i, int x){
        for(e[i+=n]=x;i>>=1;){
            e[i] = e[i*2]+e[i*2+1];
        }
    }
    int query(int l, int r){
        int ans = e[r+=n];
        for(l+=n; l<r;l/=2,r/=2){
            if(l&1)ans+=e[l++];
            if(r&1)ans+=e[--r];
        }
        return ans;
    }
};
void solve(){
    int n, q;
    cin>>n>>q;
    vector<int> x(n);
    set<int> s;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]==1)s.insert(i);
    }
    SegTree seg(x);
    int v  = 0;
    if(s.size())v=max(seg.query(0,*s.rbegin()),seg.query(*s.begin(),n-1));
    int m = seg.query(0,n-1);
    for(int i=0; i<q; i++){
        int t;
        cin>>t;
        if(t==1){
            int a;
            cin>>a;
            if(a<=v||(a%2==v%2&&a<=m)){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }else{
            int a, b;
            cin>>a>>b;
            a--;
            m-=x[a];
            if(x[a]==1){
                s.erase(a);
            }
            if(b==1){
                s.insert(a);
            }
            seg.upd(a,b);
            x[a]=b;
            if(s.size())v=max(seg.query(0,*s.rbegin()),seg.query(*s.begin(),n-1));
            else v=0;
            m+=x[a];
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}