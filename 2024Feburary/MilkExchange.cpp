#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    stack<int> s;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        ans+=x[i];
        s.push(i);
    }
    vector<int> prev(n);
    vector<int> dis(n);
    vector<int> prev2(n);
    vector<int> dis2(n);
    map<int,vector<int>> upd;
    for(int i=0; i<n; i++){
        while(!s.empty()&&x[s.top()]>=x[i]){
            s.pop();
        }
        if(!s.empty())prev[i] = s.top();
        else prev[i] = i;
        s.push(i);
        dis[i]= i-prev[i];
        if(dis[i]<0)dis[i] = n-prev[i]+i;
        upd[dis[i]].push_back(i);
        prev2[i]=prev[i];
        dis2[i]=dis[i];
    }
    vector<int> cur(n);
    iota(cur.begin(),cur.end(),0);
    for(int i=1; i<=n; i++){
        for(auto& j:upd[i]){
            ans-=x[cur[j]]-x[prev2[j]];
            cur[j] = prev2[j];
            dis2[j]=dis[prev2[j]];
            prev2[j] = prev[prev2[j]];
            if(dis2[j]!=0)upd[i+dis2[j]].push_back(j);
        }
        upd.erase(i);
        cout<<ans<<"\n";
    }
}