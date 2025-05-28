#include <bits/stdc++.h>

using namespace std;
constexpr int M = 30000000, B = 300;
vector<int> e, root;
int t1 = 0, t2 = 0;
int x[M],L[M],R[M];
int timer = 1;
int c(int a, int b, int v){
    int p = timer++;
    x[p] = x[L[p] = a]+x[R[p] = b]+v;
    return p;
}
int build(int l, int r){
    return l==r?(timer++):c(build(l,(l+r)/2),build((l+r)/2+1,r),0);
}
int kth(int v,int l, int r, int k){
    if(l==r)return l;
    if(x[L[v]]<k)return kth(R[v],(l+r)/2+1,r,k-x[L[v]]);
    return kth(L[v],l,(l+r)/2,k);
}
int has(int v, int l, int r, int k){
    if(l==r)return x[v];
    return (k<=(l+r)/2)?has(L[v],l,(l+r)/2, k):has(R[v],(l+r)/2+1,r,k);
}
int upd(int v, int l, int r, int k){
    if(l==r)return c(0,0,1);
    if(k<=(l+r)/2)return c(upd(L[v],l,(l+r)/2,k),R[v],0);
    else return c(L[v],upd(R[v],(l+r)/2+1,r,k),0);
}
int par(int i){
    return e[i]<0?i:(e[i] = par(e[i]));
}
void merge(int i, int j){
    i = par(i), j = par(j);
    if(e[i]>e[j])swap(i,j);
    e[i]+=e[j];
    e[j] = i;
}

int n, k;
vector<int> ans;
vector<pair<int,int>> s;
void rb(){
    for(int i=1; i<=n; i++)ans[i] = 1;
    for(int i = t1; i<t2; i++){
        merge(s[i].first,s[i].second);
    }
    for(int i=t2-1; i>=0; i--){
        int t = ans[s[i].first];
        ans[s[i].first]+=ans[s[i].second];
        ans[s[i].second]+=t;
    }
    t1 = t2;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>k;
    e.resize(n+1);
    root.resize(n+1);
    ans.resize(n+1);
    s.resize(n+k+k);
    vector<int> upto(n+1);
    root[0] = build(1,n);
    for(int i=1; i<=n; i++){
        e[i] = -1;
        ans[i] = 1;
        root[i] = upd(root[0],1,n,i);
    }
    for(int i=1; i<=n+k-1; i++){
        char t;
        cin>>t;
        if(t=='S'){
            int a, b;cin>>a>>b;
            if(x[root[a]]>x[root[b]])swap(a,b);
            for(int v=1; v<=x[root[a]]; v++){
                root[b] = upd(root[b],1,n,kth(root[a],1,n,v));
            }
            root[a] = root[b];
            s[t2] = make_pair(a,b);
            if((++t2)-t1== B)rb();
        }
        else if(t=='Q'){
            int a, b;
            cin>>a>>b;
            cout<<(has(root[a],1,n,b)?"yes":"no")<<"\n";
        }
        else if (t=='C'){
            int a;cin>>a;
            int ret = ans[a];
            for(int j=t1; j<t2;j++){
                auto [l,r] = s[j];
                if(upto[l]!=i&&par(l)!=par(a)&&has(root[l],1,n,a)){
                    ret++,upto[l] =i;
                }
                if(upto[r]!=i&&par(r)!=par(a)&&has(root[r],1,n,a)){
                    ret++,upto[r] =i;
                }
            }
            cout<<ret<<"\n";
        }
    }
}