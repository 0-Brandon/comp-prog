#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    vector<long long> pref;
    pref.push_back(0);
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(i>0)pref.push_back(pref[i]+x[i]-x[i-1]-1);
        else pref.push_back(x[i]-1);
    }
    //pref[0]=0
    //pref[i]=pref including gap between i and i-1
    //pref.back() includes gap between last and second last
    long long cur = 1;
    for(int i=0; i<k; i++){
        int l = lower_bound(pref.begin(),pref.end(),cur)-pref.begin()-1;
        if(l>0)cur = x[l-1]+(cur-pref[l]);
        else cur=1;
    }
    cout<<cur<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}