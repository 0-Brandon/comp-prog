#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, k;cin>>n>>k;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }
    int l=0,h=1e9+1;
    //every one we take will be greater or equal to mid
    int op = 0;
    int su = 0;
    auto act = [&](int mid){
        op=0,su=0;
        for(int i=0; i<n; i++){
            if(a[i]<mid)continue;
            int as = 1+(a[i]-mid)/b[i];
            op+=as;
            su+=a[i]*as-b[i]*as*(as-1)/2;
        }
    };
    while(l<h){
        int mid = (l+h+1)/2;
        act(mid);
        if(op>=k)l=mid;
        else h = mid-1;
    }
    act(l);
    cout<<su-(op-k)*l<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}