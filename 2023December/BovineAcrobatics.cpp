#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
    }
    sort(x.begin(),x.end()); //MAKE SURE SORT IS CORRECT ORDER
    vector<int> cap(4*n,0);
    cap[0]=m;
    int ans =0;
    for(int i=0; i<n; i++){
       // we stack min(cap,x[i].second) cows from this group
       //we add this number to cap[x[i].first+k]
       //we also add this number to ans; 
       //if there is somehow leftover (i.e. x[i].second<cap) we do cap[i+1]+=cap[i]-x[i].second;
       int na =  min(cap[i],x[i].second);
       int idx = distance(x.begin(),lower_bound(x.begin(),x.end(),make_pair(x[i].first+k,1LL*INT_MIN)));
       cap[idx]+=na;
       ans+=na;
       if(x[i].second<cap[i])cap[i+1]+=cap[i]-x[i].second;
    }
    cout<<ans<<"\n";
}