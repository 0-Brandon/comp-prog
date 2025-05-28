#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 100005;
int t[N],q[N],c[N],r[N],suf[N],d[N];
int ar[N],de[N];
signed main(){
    int n, m, k;
    cin>>n>>m>>k;
    for(int i=0; i<n-1; i++){
        cin>>d[i];
    }
    vector<array<int,3>> iv;
    for(int i=0; i<m; i++){
        int ti, a, b;
        cin>>ti>>a>>b; a--,b--;
        q[b]++;
        t[a] = max(ti,t[a]);
        iv.push_back({a,b,ti});
    }
    for(int i=n-1; i>=0; i--){
        suf[i] = suf[i+1] + q[i];
    }
    for(int i=0; i<n-1; i++){
        c[i] = (i+2<n)?suf[i+2]:0;
    }
    //calculate initial cost
    ar[0] = 0, de[0] = t[0];
    for(int i=0; i<n; i++){
        ar[i+1] = de[i]+d[i];
        de[i+1] = max(1LL*ar[i+1],t[i+1]);
    }
    int ans = 0;
    for(auto& [a,b,t]:iv){
        ans += ar[b]-t;
    }
    for(int i=0; i<n-1; i++)r[i] = min(d[i],max(0LL,de[i]+d[i]-t[i+1]));
    vector<pair<int,int>> p;
    for(int i=0; i<=n-2; i++){
        if(r[i]>0)p.emplace_back(q[i+1]+c[i],r[i]);
        if(d[i]-r[i]>0)p.emplace_back(q[i+1],d[i]-r[i]);
    }
    sort(p.rbegin(),p.rend());
    int s = 0;
    int le = k;
    for(auto& i:p){
        if(le<=0)break;
        s+=min(i.second,le)*i.first;
        le-=min(i.second,le);
    }
    cout<<ans-s;
}