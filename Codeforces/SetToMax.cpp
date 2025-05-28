#include <bits/stdc++.h>

using namespace std;

struct Seg{
    vector<int> e;int n;
    Seg(int a):e(2*a,INT_MIN),n(a){}
    int query(int l ,int r){
        int ans= e[r+=n];
        for(l+=n;l<r;l/=2,r/=2){
            if(l&1)ans = max(ans,e[l++]);
            if(r&1)ans = max(ans,e[--r]);
        }
        return ans;
    }
    void upd(int i, int a){
        for(e[i+=n]=a;i>>=1;){
            e[i] = max(e[i*2],e[i*2+1]);
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    vector<int> id(n+1,-1);
    vector<bool> ans(n,false);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    //ma is max in a, mi is min in b
    Seg ma(n),mi(n);
    for(int lol = 0 ; lol<2; lol++){
    for(int i=0; i<n; i++){
        id[a[i]]=i;
        ma.upd(i,a[i]);
        mi.upd(i,-b[i]);
        int j = id[b[i]];
        if((j!=-1)&&(ma.query(j,i)<=b[i])&&(-mi.query(j,i)>=b[i])){
            ans[i] = true;
        }
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(ans.begin(),ans.end());
    ma.e.assign(2*n,INT_MIN);
    mi.e.assign(2*n,INT_MIN);
    id.assign(n+1,-1);
    }
    for(int i=0; i<n; i++)if(!ans[i]){
        cout<<"NO\n";return;
    }
    cout<<"YES\n";return;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){solve();}
}