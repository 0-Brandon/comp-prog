#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, d, h;
    cin>>n>>d>>h;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    long double ans=(1LL*d*h)/2.0;
    for(int i=0; i<n-1; i++){
        if(x[i]+h>x[i+1]){//trapezoid
            long double nh = x[i+1]-x[i];
            long double sd = ((x[i]+h-x[i+1])/1.0/h)*d;
            ans+=(d+sd)/2.0 * nh;
        }else{//triangle
            ans+=(1LL*d*h)/2.0;
        }
    }
    cout<<ans<<"\n";
}
int main(){
    cout.precision(10); cout.setf(ios::fixed);
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}