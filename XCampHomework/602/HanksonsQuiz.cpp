#include <bits/stdc++.h>

using namespace std;


__attribute__((noinline)) void f(vector<int> &vec, int &x, int y) {
    do {
        vec.push_back(y);
        x /= y;
    } while (x % y == 0);
}
constexpr int maxp = 31623;
constexpr int P = 3401;
constexpr auto primes = []() constexpr {
    int idx = 0;
    array<int, P> res{};
    array<int, maxp> comp{};
    for (int p = 2; p < maxp; p++) {
        if (!comp[p]) {
            res[idx++] = p;
            for (int j = p; j < maxp; j += p) {
                comp[j] = 1;
            }
        }
    }
    return res;
}();

vector<int> factor(int x) {
    vector<int> vec;
    for (int i = 0; i < 3401; i++)
        if (x % primes[i] == 0)
            f(vec, x, primes[i]);
    if (x > 1)
        vec.push_back(x);
    return vec;
}
#define int long long
void solve(){
    int a, a1, b, b1;
    cin>>a>>a1>>b>>b1;
    if(gcd(a,a1)!=a1||lcm(b,b1)!=b1){
        cout<<0<<"\n";
        return;
    }
    array<map<int,int>,4> mp;
    vector<signed> fac = factor(a);
    for(int i=0; i<fac.size(); i++){
        mp[0][fac[i]]++;
    }
    fac = factor(a1);
    for(int i=0; i<fac.size(); i++){
        mp[1][fac[i]]++;
    }
    fac = factor(b);
    for(int i=0; i<fac.size(); i++){
        mp[2][fac[i]]++;
    }
    fac = factor(b1);
    for(int i=0; i<fac.size(); i++){
        mp[3][fac[i]]++;
    }
    map<int,pair<int,int>> res;
    auto is = [&](pair<int,int>& i, pair<int,int>&& j){
        return make_pair(max(i.first,j.first),min(i.second,j.second));
    };
    for(int i=0; i<4; i++){
        for(auto& [j,k]:mp[i]){
            for(int l=0; l<4; l++)mp[l][j];
        }
    }
    for(auto& [i,cnt]:mp[1]){
        if(mp[0][i]==cnt){
            res[i] = {cnt,INT_MAX};
        }
        else res[i] = {cnt,cnt};
    }
    for(auto& [i,cnt]:mp[3]){
        if(mp[2][i]==cnt){
             if(res.find(i)!=res.end())res[i] = is(res[i],{0LL,cnt});
            else res[i] = {0LL,cnt};
        }
        else{
           if(res.find(i)!=res.end())res[i] = is(res[i],{cnt,cnt});
           else res[i] = {cnt,cnt};
        }
    }
    int ans = 1;
    for(auto& [i,p]:res){
        if(mp[3][i]==0&&p.second-p.first>1)p.second=p.first;
        if(p.second-p.first<0){
            cout<<"0\n";
            return;
        }
        ans*=(p.second-p.first+1);
    }
    cout<<max(ans,0LL)<<"\n";
}


signed main(){
    int n;
    cin>>n;
    while(n--)solve();
}
