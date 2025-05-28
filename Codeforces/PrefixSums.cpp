#include <bits/stdc++.h>
#define int long long
using namespace std;
int MM = 2e18;
int C(int n, int r){
    if(n < 0 || r < 0 || r > n)return 0L;
    if(r>n-r)r=n-r;
    int ans = 1;
    for(int i=1; i<=r; i++){
        int div = i, mul = n-i+1;
        if((double)ans/div*mul>MM)return MM;
        int g = gcd(div,mul);
        ans = ans/(div/g)*(mul/g);
        if(ans>=MM)return MM;
    }
    return ans;
}
signed main(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(x[i]>=k){
            cout<<0<<" ";return 0;
        }
    }
    auto ok = [&] (int r){
        int sum = 0;
        for(int i=0; i<n; i++){
            if(x[i]==0)continue;
            int t = C(n-i+r-1-1,n-i-1);
            if((double)t*x[i]>=MM){
                sum = MM;
                break;
            }
            sum+=t*x[i];
            if(sum>=k)break;
        }
        return sum>=k;
    };
    int l = 0, h = k+1;
    while(l<h){
        int mid = l+(h-l)/2;
        if(ok(mid)){
            h = mid;
        }else{
            l = mid+1;
        }
    }
    cout<<l<<" ";
}