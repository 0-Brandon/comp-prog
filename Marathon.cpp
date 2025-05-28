#include <bits/stdc++.h>

using namespace std;
int dist(pair<int,int> i,pair<int,int> j){
    return abs(i.first-j.first)+abs(i.second-j.second);
}
vector<pair<int,int>> x;
int main(){
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    x.resize(n);
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x[i]={a,b};
    }
    int sum = 0;
    int ans = 0;
    for(int i=1; i<n-1; i++){
        sum+=dist(x[i-1],x[i]);
        int wo = dist(x[i-1],x[i+1]);
        int w = dist(x[i-1],x[i])+dist(x[i],x[i+1]);
        ans=max(w-wo,ans);
    }
    sum+=dist(x[n-1],x[n-2]);
    cout<<sum-ans<<"\n";
}