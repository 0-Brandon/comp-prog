#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    map<int,int> mp;
    //alice can take one element with number 1, and every element appearing more than once
    for(int i=0; i<n; i++){
        cin>>x[i];
        mp[x[i]]++;
    }
    bool b=1;
    vector<int> a(n+1);
    for(auto& [i,c]:mp){
        if(c==1){
            if(b){
                b=0;
                a[i]=1;
            }
        }
        else{
            a[i]=1;
        }
    }
    for(int i=0; i<=n; i++){
        if(a[i]==0){cout<<i<<"\n";return;}
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}