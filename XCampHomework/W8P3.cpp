#include <bits/stdc++.h>
using namespace std;
//1d/1d
/*
dp[i]  = maxj -a[i]+y[i]*(x[i])+

(-x[j])*y[i]+dp[j]
-x[j] only decreases
queries sorted 

dp[i] = -a[i]+x[i]*y[i]   -x[j]*y[i]+dp[j]
*/

struct line{
    long long m, b;
    long long operator()(long long x){return m*x+b;}
    double is(line e){return (double)(b-e.b)/(e.m-m);}
};
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> x(n,0),y(n,0);
    vector<long long> a(n,0);
    vector<int> ord(n,0);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
        cin>>a[i];
        ord[i]=i;
    }
    long long ans=0;
    sort(ord.begin(),ord.end(),[&](int i, int j){return x[i]<x[j];});
    deque<line> dq;
    dq.push_back({0,0});
    for(auto& i:ord){
        while(dq.size()>=2 && dq.back()(y[i])<=dq[dq.size()-2](y[i])){
            dq.pop_back();
        }
        long long cur = -a[i]+y[i]*1LL*x[i]+dq.back()(y[i]);
        ans = max(ans,cur);
        line curl = {-x[i],cur};
        while(dq.size()>=2 && curl.is(dq[0])>=dq[0].is(dq[1])){
            dq.pop_front();
        }
        dq.push_front(curl);
    }
    cout<<ans<<"\n";
}