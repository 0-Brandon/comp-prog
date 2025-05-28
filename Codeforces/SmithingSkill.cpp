//#pragma GCC target("bmi,bmi2,avx2,lzcnt,popcnt")
//#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first;
    }
    for(int i=0; i<n; i++)cin>>x[i].second;
    sort(x.begin(),x.end(),[&](auto i, auto j){return i.first<j.first;});
    int mdif = -1;
    vector<long long> dp(2e6+5,0);
    int p = 0;
    for(int i=0; i<2e6+5; i++){
        while(p<n&&x[p].first==i){
            if(mdif==-1||x[p].first-x[p].second<x[mdif].first-x[mdif].second)mdif=p;
            p++;
        }
        if(mdif!=-1&&i-(x[mdif].first-x[mdif].second)>=0)dp[i] = dp[i-(x[mdif].first-x[mdif].second)]+1;
    }
    long long tot = 0;
    for(int i=0; i<m; i++){
        int q;cin>>q;
        if(q<=2e6){
            tot+=dp[q];
        }
        else{
            long long ans = 0;
            long long times = (q-x[mdif].first)/(x[mdif].first-x[mdif].second)+1;
            ans+=times;
            q-=times*(x[mdif].first-x[mdif].second);
            ans+=dp[q];
            tot+=ans;
        }
    }
    cout<<tot*2;
}