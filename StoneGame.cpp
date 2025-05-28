#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    int ma = 0;
    vector<int> pre(1e6+10);
    for(int i=0; i<n; i++){
        int t;cin>>t;pre[t]++;
        ma = max(t,ma);
    }
    for(int i=1; i<=ma; i++){
        pre[i]+=pre[i-1];
    }
    int ans = 0;
    vector<int> cnt(1e6+10,0);
    for(int k=1; k<=ma; k++){
        int odd = 0, fi = 0;
        for(int mul = 1; mul*k<=ma; mul++){
            cnt[mul] = pre[min(mul*k+k-1,ma)]-pre[mul*k-1];
            if(cnt[mul]%2==1){
                odd++;
                if(odd==1)fi = mul;
                else if(fi!=mul-1)odd++;
                if(odd>2)break;
            }
        }
        if(odd==2)ans+=cnt[fi+1];
        if(odd==1&&fi==1)ans+=cnt[1];
    }
    cout<<ans<<"\n";
}