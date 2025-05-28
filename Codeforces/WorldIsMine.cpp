#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> x(n);map<int,int> cnt;
    for(int i=0; i<n; i++){
        cin>>x[i];cnt[x[i]]++;
    }
    int ans = 0;
    int acc = 0;
    priority_queue<int> pq;
    for(auto& [i,j]:cnt){
        if(acc>=j){
            acc-=j;
            pq.push(j);
            continue;
        }
        if(pq.size()&&j<pq.top()){
            acc+=pq.top()+1;
            pq.pop();
            ans++;
        }
        if(acc>=j){
            acc-=j;
            pq.push(j);
            continue;
        }
        ans++;
        acc++;
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}