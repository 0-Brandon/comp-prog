#include <bits/stdc++.h>

using namespace std;

struct Segtree{
    int n;
    vector<int> e;
    Segtree(vector<int>& x):n(x.size()),e(2*n){}
    void upd(int i, int j){
        for(e[i+=n] = j; i>>=1;)e[i] = max(e[i*2],e[i*2+1]);
    }
    int query(int l, int r){
        int ans = 0;
        for(ans = e[r+=n], l+=n; l<r; l/=2,r/=2){
            if(l&1)ans = max(ans,e[l++]);
            if(r&1)ans = max(ans,e[--r]);
        }
        return ans;
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<vector<int>> id(n+1);
    for(int i=0; i<n; i++){
        cin>>x[i];
        id[x[i]].push_back(i);
    }
    Segtree seg(x);
    int m =0;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        m = max(m,x[i]);
        ans[i] = m;
    }
    vector<int> res(n+1);
    for(int i=1; i<=n; i++){
        for(auto& j:id[i]){
            seg.upd(j, ans[j]);
            res[j] = seg.query(j,n-1);
        }
    }
    vector<int> mp(n+1);
    for(int i=0; i<n; i++){
        if(mp[res[i]]){
            res[i] = mp[res[i]];
            continue;
        }
        vector<int> list;
        int p = i;
        while(res[p]!=x[p])list.push_back(p),p = id[res[p]][0];
        for(auto& i:list)mp[res[i]] = res[p];
        mp[res[i]] = res[p];
        res[i] = res[p];
    }
    res.pop_back();
    for(auto& i:res)cout<<i<<" ";cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}