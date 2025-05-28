#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    map<int,int> cnt;
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]]++;
    }
    multiset<int> a, b;
    for(auto& i:cnt)b.insert(i.second);
    int holes = 0;
    int sum = 0;
    int ans = INT_MAX;
    for(int i=0; i<=n; i++){
        while(!b.empty()&&sum+(*b.begin())<=k){
            sum+=*b.begin();
            a.insert(*b.begin());
            b.erase(b.begin());
        }
        if(k>=holes){
            ans = min(ans,(int)b.size());
        }
        if(a.find(cnt[i])!=a.end()){
            a.erase(a.find(cnt[i]));
            sum-=cnt[i];
        }
        else{
            if(b.find(cnt[i])!=b.end())b.erase(b.find(cnt[i]));
        }
        if(cnt[i]==0){
            holes++;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}