#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int  n, k;cin>>n>>k;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++)cin>>x[i].first>>x[i].second;
    sort(x.begin(),x.end());
    int p=0, ans =0;
    priority_queue<int, vector<int>,greater<int>> pq;
    int t=0;
    while(p<n||pq.size()){
        while(p<n&&x[p].first==t)pq.push(x[p].second), p++;
        for(int i=0; i<k; i++){
            if(pq.empty())break;
            ans = max(ans, t-pq.top());
            pq.pop();
        }
        if(pq.empty()){
            if(p==n)break;
            t=x[p].first;
        }
        else t++;
    }
    cout<<ans<<"\n";
}