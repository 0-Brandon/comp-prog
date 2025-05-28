#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> v;
int cnt(int l, int r, int c){
    return upper_bound(v[c].begin(),v[c].end(),r)-lower_bound(v[c].begin(),v[c].end(),l);
}
int n;
vector<int> a;
vector<int> t;
void build(int idx = 0, int dl =0 , int dh = n-1){
    if(dl==dh){
        t[idx] = a[dl];
        return;
    }
    int mid = (dl+dh)/2;
    build(idx*2+1,dl,mid);
    build(idx*2+2, mid+1, dh);
    t[idx] = (cnt(dl,dh, t[idx*2+1])>cnt(dl,dh,t[idx*2+2]))?t[idx*2+1]:t[idx*2+2];
}
int query(int idx, int dl, int dh, int l, int r){
    if(dl>r||dh<l)return 0;
    if(dl>=l&&dh<=r)return cnt(l,r,t[idx]);
    int mid = ((dl+dh)/2);
    return max(query(idx*2+1,dl,mid,l,r),query(idx*2+2, mid+1, dh, l, r));
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int q;
    cin>>n>>q;
    a.resize(n);
    v.resize(n+1);
    t.resize(4*n+1);
    for(int i=0; i<n; i++){
        cin>>a[i];
        v[a[i]].push_back(i);
    }
    build();
    for(int i=0; i<q; i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int e = query(0,0,n-1,l,r);
        int le = r-l+1;
        cout<< ((e<=le/2)?1: (2*e-le))<<"\n";
    }
}