#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    int c = n;
    vector<int> x(n);
    vector<int> time(n,0);
    vector<int> first(n+1,n);
    vector<int> last(n+1,0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        first[x[i]] = min(first[x[i]],i);
        last[x[i]] = max(last[x[i]],i);
        time[max(0,i-x[i]+1)]--;
        if(i+x[i]<n)time[i+x[i]]++;
    }
    int l=n, r =0;
    for(int i=0; i<=n; i++){
        l = min(l,first[i]);
        r = max(r,last[i]);
        if(r-l+1>i){cout<<"0\n";return;}
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        c+=time[i];
        ans+=(c==0);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}