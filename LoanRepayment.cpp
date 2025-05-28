#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    cin.tie(0)->sync_with_stdio(false);
    freopen("loan.in","r",stdin);
    freopen("loan.out","w",stdout); 
    int n, k, m;
    cin>>n>>k>>m;
    auto ok = [&] (int x, int n, int k, int m){
        int g = 0;
        while(k>0&&g<n){
            int y = (n-g)/x;
            if(y<m){
                int rem  = (n-g+m-1)/m;
                return rem<=k;
            }
            int range = n-g-y*x;
            int sub = min(k,range/y+1);//num turns
            g+=sub*y;
            k-=sub;
        }
        return g>=n;
    };
    int l=1,h=1e12; 
    while(l<h){
        int mid = (l+h+1)/2;
        if(ok(mid,n,k,m)){
            l = mid;
        }else{
            h = mid-1;
        }
    }
    cout<<l;
}