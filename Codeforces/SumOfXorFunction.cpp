#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 0;
    for(int b=0; b<=30; b++){
        vector<int> cnt(2,0);
        cnt[0]=1;
        vector<int> sum(2,0);
        int cur = 0;
        for(int i=0; i<n; i++){
            if(x[i]&(1<<b))cur^=1;
            cnt[cur]++;
            sum[cur]= (sum[cur]+i+1)%mod;
            int te = (cnt[cur^1] * (i+1) - sum[cur^1])%mod;
            //we go by bit
            //we only look at indices such that the subarray to i will be 1 at this bit
            //we can fctor out 1<<b
            //now we are left with 1<<b * (sum of all right bounds- (sum of all left bounds))
            //the right bound is i, so we have (num subarray) * i - sum of all left bound
            //we store sum of all indices that end in prefix of 1 or 0 in sum and use that for sum of all left bounds
            te = (te * (1<<b))%mod;
            ans  = (ans+te)%mod;
        }
    }
    cout<<ans<<"\n";
}