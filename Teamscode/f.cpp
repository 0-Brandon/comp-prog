#include <bits/stdc++.h>
using namespace std;
int LOG = 23;
int m = 5*1e6+1;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n,x;cin>>n>>x;
    vector<int> p(n),q(n);
    vector<int> su(n);
    for(int i=0; i<n; i++){
        cin>>p[i];
        int t = p[i];
        while(t){
            su[i]+=t%10;t/=10;
        }
    }
    for(int i=0; i<n; i++){
        cin>>q[i];
    }
    exit();
    map<long long,int> dp;
    dp[x]=1;
    for(int i=0; i<n;i++){
        map<long long,int> cur;
        for(int j=m; j>=0; j--){
            cur[j+p[i]]+=dp[j];
            if(su[i]<=LOG)cur[j^(1<<su[i])]+=dp[j];
        }
        swap(cur,dp);
        int ans = 0;
        for(int j=0; j<=q[i]; j++){
            ans+=dp[j];
        }
        cout<<ans<<"\n";
    }
}