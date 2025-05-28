#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

constexpr int base = 13331;

signed main() {
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> pre(n+1);
    pre[0] = 1;
    vector<pair<int,int>> a(n),b(n);
    for(int i=0; i<n; i++)pre[i+1] = pre[i]*base;
    vector<int> c1,c2;
    for(int i=0; i<n; i++){
        cin>>a[i].first>>b[i].first>>a[i].second>>b[i].second;
        c1.push_back(a[i].first);
        c1.push_back(a[i].second);
        c2.push_back(b[i].first);
        c2.push_back(b[i].second);
    }
    c1.push_back(x);
    c2.push_back(y);
    sort(c1.begin(),c1.end());
    sort(c2.begin(),c2.end());
    c1.erase(unique(c1.begin(),c1.end()), c1.end());
    c2.erase(unique(c2.begin(),c2.end()), c2.end());
    vector<int> h1(c1.size()*2), h2(c2.size()*2);
    for(int i=0; i<n; i++){
        a[i].first = lower_bound(c1.begin(),c1.end(),a[i].first) - c1.begin();
        a[i].second = lower_bound(c1.begin(),c1.end(),a[i].second) - c1.begin();
        b[i].first = lower_bound(c2.begin(),c2.end(),b[i].first) - c2.begin();
        b[i].second = lower_bound(c2.begin(),c2.end(),b[i].second) - c2.begin();
        h1[a[i].first]+=pre[i+1];
        h1[a[i].second]-=pre[i+1];
        h2[b[i].first]+=pre[i+1];
        h2[b[i].second]-=pre[i+1];
    }
    unordered_map<int,int> mp;
    int cur = 0;
    int ans1=0,ans2=0;
    for(int i=0; i<c1.size(); i++){
        if(i>0)mp[cur]+=c1[i]-c1[i-1];
        else mp[cur]+=c1[i];
        ans1 = max(ans1,mp[cur]);
        cur+=h1[i];
    }
    mp.clear();
    for(int i=0; i<c2.size(); i++){
        if(i>0)mp[cur]+=c2[i]-c2[i-1];
        else mp[cur]+=c2[i];
        ans2 = max(ans2, mp[cur]);
        cur+=h2[i];
    }
    cout<<ans1*ans2<<"\n";
}