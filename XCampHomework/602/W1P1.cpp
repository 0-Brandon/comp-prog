#include <bits/stdc++.h>

using namespace std;
constexpr array<int,6> primes = {2,3,5,7,11,13};
struct segtree{
    int n;
    vector<int> e;
    segtree(vector<int> x):n(x.size()),e(2*n){
        for(int i=n; i<2*n; i++){
            e[i] = x[i-n];
        }
        for(int i=n-2; i>0; i--){
            e[i] = gcd(e[i*2],e[i*2+1]);
        }
    }
    int query(int l, int r){
        int ans = 0;
        for(l+=n,ans=e[r+=n]; l<r; l/=2,r/=2){
            if(l&1)ans = gcd(ans,e[l++]);
            if(r&1)ans = gcd(ans,e[--r]);
        }
        return ans;
    }
};
int exp(int a, int b){
    int ans = 1;
    for(;b;b/=2){
        if(b&1)ans*=a;
        a*=a;
    }
    return ans;
}
void solve(){
    int n, m;cin>>n>>m;
    vector<vector<pair<int,int>>> time(n+1);
    vector<array<int,3>> qu;
    for(int i=0; i<m; i++){
        int a, b, c;cin>>a>>b>>c;a--,b--;
        time[a].push_back({c,1});
        time[b+1].push_back({c,0});
        qu.push_back({a,b,c});
    }
    vector<int> ans(n);
    int lcm = 1;
    map<int,map<int,int>> cnt;
    for(int i=0; i<n; i++){
        for(auto& [a,t]:time[i]){
            for(auto& p:primes){
                int c = 0;
                while(a%p==0)a/=p,c++;
                if(cnt[p].size())lcm/=exp(p,cnt[p].rbegin()->first);
                if(t){
                    cnt[p][c]++;
                }
                else{
                    cnt[p][c]--;
                    if(cnt[p][c]==0)cnt[p].erase(c);
                }
                if(cnt[p].size())lcm*=exp(p,cnt[p].rbegin()->first);
            }
        }
        ans[i] = lcm;
    }
    segtree seg(ans);
    for(auto& [l,r,g]:qu){
        if(seg.query(l,r)!=g){cout<<"Impossible\n";return;}
    }
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    solve();
}