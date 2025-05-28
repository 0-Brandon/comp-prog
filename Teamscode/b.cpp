#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, ma,mi, ex;cin>>n>>ma>>mi>>ex;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int cma=0, cmi=INT_MAX, maid=-1,miid=-1;
    int lim = -1;
    //lim is not inclusive
    //any start index from lim to min(maid,miid) until i should work
    int ans = 0;
    for(int i=0; i<n; i++){
        if(cma<=x[i])cma=x[i],maid = i;
        if(cmi>=x[i])cmi=x[i],miid = i;
        if(x[i]==ex||x[i]>ma||x[i]<mi)lim =i,cma = 0,cmi = INT_MAX, maid = -1,miid = -1;
        if(cma==ma&&cmi==mi)ans+=max(0LL,min(maid,miid)-lim);
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}