#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    vector<int> x(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){
        cin>>x[i];
        mp[x[i]]++;
    }
    int p=0;
    while(true){
        if(mp[p]==0){cout<<p<<"\n";return;}
        mp[p+k]+=mp[p]-1;
        p++;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}