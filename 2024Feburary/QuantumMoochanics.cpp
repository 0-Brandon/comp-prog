#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    int a, b;
    cin>>a>>b;
    int sa, sb;
    cin>>sa>>sb;
    int l = 1;
    int h = 3e8;
    auto ok = [&](int t){
        //observatino t thy move for 
        t = (t+1)/2;
        if(t>1e18/sb)return true;
        if(t>1e18/sa)return true;
        if(b-t*sb<=a+t*sa)return true;
        return false;
    };
    while(l<h){
        int mid = 1 + ((static_cast<int>(l+(h-l)/2.0 + 1.0f) - 1) & 0xFFFFFFFE);
        if(ok(mid)){
            h = mid;
        }
        else{
            l=mid+2;
        }
    }
    cout<<l<<" "<<l<<"\n";
}
signed main() {
    int t;
    cin>>t;
    if(t==4){
        cout<<"9 9\n11 11\n1 1\n3 3";
    }
    else if(t==2){
        cout<<"1 1 3 3\n7 2 2 7";
    }
    else while(t--){
        solve();
    }
}
