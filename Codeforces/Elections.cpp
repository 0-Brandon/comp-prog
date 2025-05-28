#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree{
    int n;
    vector<int> e, p;
    SegTree(vector<int>& x):n(x.size()),e(2*n),p(2*n){
        for(int i=n;i<2*n; i++){
            e[i]=x[i-n];
            p[i] = 1;
        }
        for(int i=n-1; i>0; i--){
            e[i] = e[i*2]+e[i*2+1];
            p[i]=p[i*2]+p[i*2+1];
        }
    }
    pair<int,int> query(int l, int r){
        if(l>r)return {0,0};
        pair<int,int> ans;
        for(l+=n,ans = {e[r+=n],p[r]};l<r;l/=2,r/=2){
            if(l&1)ans.first+=e[l],ans.second+=p[l++];
            if(r&1)ans.first+=e[r],ans.second+=p[--r];
        }
        return ans;
    }
    void upd(int i){
        for(e[i+=n]=0,p[i]=0;i>>=1;){
            e[i] = e[i*2]+e[i*2+1];
            p[i] = p[2*i]+p[i*2+1];
        }
    }
};
void solve(){
    int n,c;
    cin>>n>>c;
    vector<int> x(n),y(n),rev(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(i==0)x[i]+=c;
        y[i]=x[i];
    }
    vector<int> s(n);
    iota(s.begin(),s.end(),0);
    sort(s.begin(),s.end(),[&](int i, int j){return x[i]<x[j];});
    for(int i=0; i<n; i++){
        rev[s[i]]=i;
    }
    sort(y.begin(),y.end());
    SegTree seg(y);
    //going through x
    vector<int> suf(n);
    suf.back()=x.back();
    for(int i=n-2; i>=0; i--){
        suf[i] = max(suf[i+1],x[i]);
    }
    suf.push_back(0);
    int acc = 0;
    bool b = false;
    for(int i=0; i<n; i++){
        if(x[i]==x[s.back()]&&!b){cout<<0<<" ";b=true;}
        else{
        int ans = i;
        int l=0, h=n;
        while(l<h){
            int mid = (l+h+1)/2;
            pair<int,int> res = seg.query(mid,n-1);
            if(res.first+acc+x[i]>=suf[i+1])l=mid;
            else h = mid-1;
        }
        cout<<ans+seg.query(l,n-1).second<<" ";
        }
        acc+=x[i];
        seg.upd(rev[i]);
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}