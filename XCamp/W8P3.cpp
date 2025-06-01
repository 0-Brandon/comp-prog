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
    int m, b;
    int operator()(int x){return m*x+b;}
    int is(line e){return (e.b-b)/(m-e.m);}
};
int main(){
    int n;
    cin>>n;
    vector<int>x(n),y(n),a(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i]>>a[i];
    }
    vector<int> dp(n,0);
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int i, int j){return x[i]<x[j];});
    deque<line> dq;
    dq.push_back({0,0});
    for(auto& i:ord){
        dp[i] = -a[i]+y[i]*x[i];
        while(dq.size()>=2 && dq.back()(y[i])<=dq[dq.size()-2](y[i]))dq.pop_back();
        dp[i]+= dq.back()(y[i]);
        line cur = {-x[i],dp[i]};
        while(dq.size()>=2 && cur.is(dq[0])>=dq[0].is(dq[1]))dq.pop_front();
        dq.push_front(cur);
    }
    cout<<dp[ord.back()];
}