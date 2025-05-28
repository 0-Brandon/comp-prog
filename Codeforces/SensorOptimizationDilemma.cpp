#include <bits/stdc++.h>
#define int long long
using namespace std;
//atcoder problem secretly
signed main(){
    int n, x;cin>>n>>x;
    int l=0, h=1e9;
    vector<int> a(n),ax(n),b(n),bx(n);
    for(int i=0; i<n; i++){
        int a1, b1, c, d;cin>>a1>>b1>>c>>d;
        if(a1*d<c*b1)swap(a1,c),swap(b1,d);
        a[i] = a1,ax[i]=b1,b[i]=c, bx[i] = d;
    }
    auto ok = [&](int w)->bool {
        int ans = 0;
        for(int i=0; i<n; i++){
            int cur = INT_MAX;
            for(int j=0; j<lcm(a[i],b[i])+2; j++){
                //j b[i] machines
                int cost = j*bx[i]+(w-j*b[i]+a[i]-1)/a[i]*ax[i];
                cur = min(cur,cost);
            }
            ans+=cur;
        }
        return ans<=x;
    };
    while(l<h){
        int mid = l+(h-l+1)/2;
        if(ok(mid)){
            l = mid;
        }else{
            h = mid-1;
        }
    }
    cout<<l<<" ";
}