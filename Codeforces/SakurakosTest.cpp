#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,q; cin>>n>>q;
    vector<int> x(n);
    vector<int> cnt(2*n+1,0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        cnt[x[i]]++;
    }
    vector<int> pref(2*n,0);
    for(int i=0; i<pref.size()-1; i++){
        pref[i+1] = pref[i]+cnt[i];
    }
    vector<int> ans(n+1,-1);
    while(q--){
        int a;cin>>a;
        if(ans[a]!=-1){cout<<ans[a]<<" ";continue;}
        int l=0, h = a-1;
        while(l<h){
            int g = 0;
            int mid = l+(h-l)/2;
            for(int k=0; k*a+mid+1<pref.size(); k++){
                g+=pref[k*a+mid+1]-pref[k*a];
            }
            if(g>(n)/2){
                h = mid;
            }
            else l = mid+1;
        }
        ans[a] = l;
        cout<<ans[a]<<" ";
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){
        solve();
    }
}