#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("maxcross.in","r",stdin);
    freopen("maxcross.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, b;
    cin>>n>>k>>b;
    vector<int> x(b);
    for(int i=0; i<b; i++){
        cin>>x[i];
        x[i]--;
    }
    sort(x.begin(),x.end());
    vector<int> pref(n+1,0);
    int bidx=0;
    for(int i=1; i<=n; i++){
        pref[i]=pref[i-1];
        if(x[bidx]==i-1){
            pref[i]++;
            bidx++;
        }
    }
    int ans = INT_MAX;
    for(int i=1; i<=n-k; i++){
        ans = min(ans,pref[i+k]-pref[i]);
    }
    cout<<ans;
}