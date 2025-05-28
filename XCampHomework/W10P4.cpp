#include <bits/stdc++.h>
using namespace std;

signed main(){
    int n, t;
    cin>>n>>t;
    vector<long long> x(n+1,0LL);
    for(int i=1; i<=n; i++)cin>>x[i];
    vector<pair<int,int>> q;
    vector<int> s(t);
    vector<long long> ans(t);
    for(int i=0; i<t; i++){
        s[i]=i;
        int l, r;
        cin>>l>>r;
        q.push_back({l,r});
    }
    auto b = [&](int i){return i/1000;};
    sort(s.begin(),s.end(),[&](auto i, auto j){
        return (b(q[i].first)==b(q[j].first))?
        (q[i].second>q[j].second):
        (b(q[i].first)<b(q[j].first));}
        );
    int l=0, r=0;
    vector<int> cnt(1e6+1,0);
    long long cur = 0;
    for(auto& i:s){
        //add needed
        while(r<q[i].second){
            r++;
            cur-=1LL*cnt[x[r]]*cnt[x[r]]*x[r];
            cnt[x[r]]++;
            cur+=1LL*cnt[x[r]]*cnt[x[r]]*x[r];
        }
        while(l>q[i].first){
            l--;
            cur-=1LL*cnt[x[l]]*cnt[x[l]]*x[l];
            cnt[x[l]]++;
            cur+=1LL*cnt[x[l]]*cnt[x[l]]*x[l];
        }
       // remove excess
        while(r>q[i].second){
            cur-=1LL*cnt[x[r]]*cnt[x[r]]*x[r];
            cnt[x[r]]=max(0,cnt[x[r]]-1);
            cur+=1LL*cnt[x[r]]*cnt[x[r]]*x[r];
            r--;
        }
        while(l<q[i].first){
            cur-=1LL*cnt[x[l]]*cnt[x[l]]*x[l];
            cnt[x[l]]=max(0,cnt[x[l]]-1);
            cur+=1LL*cnt[x[l]]*cnt[x[l]]*x[l];
            l++;
        }
        ans[i] = cur;
    }
    for(auto& i:ans)cout<<i<<"\n";
}