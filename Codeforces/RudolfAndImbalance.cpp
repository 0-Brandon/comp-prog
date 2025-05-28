#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> x(n),d(m),f(k);
    int me = -1;
    int ans;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(i==0)continue;
        me = max(me,x[i]-x[i-1]);
    }
    for(int i=0; i<m; i++){
        cin>>d[i];
    }
    for(int i=0; i<k; i++)cin>>f[i];
    int cnt = 0;
    int a, b;
    for(int i=1; i<n; i++)if(x[i]-x[i-1]==me){
        cnt++;
        a=x[i-1],b=x[i];
    }
    if(cnt>1){
        cout<<me<<"\n";
        return;
    }
    ans=me;
    sort(d.begin(),d.end());
    sort(f.begin(),f.end());
    int mid = (a+b)/2;
    for(auto& i:d){
        auto it = lower_bound(f.begin(),f.end(),mid-i);
        if(it!=f.end())ans = min(ans,max(b-(*it+i),(*it+i)-a));
        if(it==f.begin())continue;
        it--;
        ans = min(ans,max(b-(*it+i),(*it+i)-a));
        //we search in f for mid-i
    }
    for(int i=1; i<n; i++)if(x[i]-x[i-1]!=me&&x[i]-x[i-1]>ans)ans = x[i]-x[i-1];
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}