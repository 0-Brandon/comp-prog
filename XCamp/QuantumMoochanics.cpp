#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n),s(n);
    for(int i=0; i<n; i++)cin>>x[i];
    for(int i=0; i<n; i++)cin>>s[i];
    priority_queue<array<int,3>> pq;
    //calculate intersection time between i and j
    auto time = [&](int i, int j){
        int op=1;
        if(i%2!=j%2)op=0;
        int d = x[j]-x[i];
        int s1 = s[i]+s[j];
        int t = (d+s1-1)/s1;
        if(t%2!=op)t++;
        return t;
    };
    for(int i=1; i<n; i++){
        pq.push({time(i-1,i),i-1,i});
    }
    vector<int> ans(n,-1);
    int cnt = 0;
    auto obs = [&](int t){
        int l = 0, h = t;
        while(l<h){
            int mid = (l+h)/2;
            if(mid*(mid+1)/2<=t)l = mid;
            else h = mid-1;
        }
        return l;
    };
    while(cnt<n&&!pq.empty()){
        auto cur = pq.top();pq.pop();
        int t = cur[0],x = cur[1],y=cur[2];
        if(ans[x]!=-1||ans[y]!=-1)continue;
        ans[x] = ans[y] = obs(t);
        if(x>0&&y<n)pq.push({time(x-1,y+1),x-1,y+1});
        cnt++;
    }
    for(auto& i:ans)cout<<i<<" ";
}
int main(){
   // cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cout<<t<<"a\n";
        solve();
    }
}