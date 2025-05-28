
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    int ans = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        ans = max(ans,x[i]);
    }
    ans = min(ans,n*(n+1)/2);
    sort(x.begin(),x.end());
    for(int i=1; i<=n; i++){
        bool f= true;
        vector<bool> marked(n,0);
        for(int j = i, inc = i-1; inc>=0; j+=inc,inc--){
            int ind = distance(x.begin(),lower_bound(x.begin(),x.end(),j));
            if(marked[ind]){
                f=false;
                break;
            }
            marked[ind] = true;
            if(marked.back())break;
        }
        if(!f)continue;
        if(marked.back()){
            ans =min(ans, i*(i+1)/2);
        }
        else{
            ans = min(ans,x.back());
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}