#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 1LL<<62;
int n, m;
vector<int> a;  
unordered_map<int, int> memo[205];
int next_number(int x, int k){
    if(k==0&&x>=0)return INF;
    if(k==0)return 0;
    ++x;
    while(__builtin_popcountll(x)>k){x|=x-1; x++;}
    for (int i=k-__builtin_popcountll(x); i; i--)x|=x+1;
    return x;
}
int f(int i, int prev) {
    if (i==n) return 0;
    if (memo[i].count(prev)) return memo[i][prev];
    int& ans = memo[i][prev] = -INF;
    for (int k = 0; k <= 60; ++k) {
        int v = next_number(prev, k);
        if (v<=m) ans = max(ans, a[i]*k+f(i+1,v));
    }
    return ans;
}
signed main(){
    cin>>n>>m;
    a.resize(n);
    for(int i=0; i<n; i++)cin>>a[i];
    cout<<f(0, -1);
}