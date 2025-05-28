#include <bits/stdc++.h>
#define int long long
using namespace std;

struct line{
    int m, b;
    int operator()(int x){
        return m*x+b;
    }
};
//dp[i] = minj dp[j+1] + s*(f[n]-f[i-1])+(t[j]-t[i-1])*(f[n]-f[i-1])
//dp[i] = minj dp[j+1] + (s+t[j]-t[i-1])*(f[n]-f[i-1])
//dp[i] = minj (s-t[i-1])*(f[n]-f[i-1]) + (t[j]*f[n]-t[j]*f[i-1])
//slope is -t[j], it is constantly increasing
//query is f[i-1], it i constantly decreasing  
//dp[i]
//dp[i] = minj dp[j-1] + s*(f[n]-f[j]) + (t[i])*(f[i]-f[j]) 

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, S;
    cin>>n>>S;
    vector<int> f(n+1,0);
    vector<int> t(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>t[i]>>f[i];
        t[i]+=t[i-1];
        f[i]+=f[i-1];
    }
    vector<int> dp(n+5,0);
    deque<line> dq;
    for(int i=n-1; i>=0; i--){
        line cur = {-t[i+1],dp[i+1]+t[i+1]*f[n]};
        while(dq.size()>=2 && (dq[0].b-cur.b)/(cur.m-dq[0].m)>=(dq[0].b-dq[1].b)/(dq[1].m-dq[0].m)){
            dq.pop_front();
        }
        dq.push_front(cur);
        dp[i] = (S-t[i])*(f[n]-f[i]);
        while(dq.size()>=2 && dq.back()(f[i])>=dq[dq.size()-2](f[i]))dq.pop_back();
        dp[i]+=dq.back()(f[i]);
    }
    cout<<dp[0]<<"\n";
}