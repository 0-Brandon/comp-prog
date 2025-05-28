#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, q;cin>>n>>q;
    vector<int> par(n);
    vector<set<int>> ch(n);
    vector<int> rev(n);
    for(int i=1; i<n; i++){
        cin>>par[i];par[i]--;
    }
    vector<int> p(n);
    for(int i=0; i<n; i++){cin>>p[i];p[i]--;rev[p[i]]=i;}
    for(int i=0; i<n; i++){
        if(p[i]!=0)ch[par[p[i]]].insert(i);
    }
    vector<int> sub(n,1);
    for(int i=n-1; i>0; i--){
        sub[par[i]]+=sub[i];
    }
    int cnt = 0;
    auto check = [&](int i){
        if(ch[i].empty())return true;
        return rev[i]<=*ch[i].begin()&&rev[i]+sub[i]>=*--ch[i].end()+sub[p[*--ch[i].end()]];
    };
    for(int i=0; i<n; i++){
        cnt+=check(i);
    }
    while(q--){
        int a, b;cin>>a>>b;a--,b--;
        set<int> cur;
        cur.insert(p[a]);cur.insert(p[b]);cur.insert(par[p[a]]);cur.insert(par[p[b]]);
        for(auto& i:cur){
            cnt-=check(i);
        }
        ch[par[p[a]]].erase(a);
        ch[par[p[b]]].erase(b);
        ch[par[p[a]]].insert(b);
        ch[par[p[b]]].insert(a);
        swap(rev[p[a]],rev[p[b]]);
        swap(p[a],p[b]);
        for(auto& i:cur){
            cnt+=check(i);
        }
        if(cnt==n)cout<<"YES\n";
        else cout<<"NO\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}