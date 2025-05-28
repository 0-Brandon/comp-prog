#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n,0);
    int cnt=0, ans=0;
    for(int i=0; i<n; i++){
        if(cnt<(i+k-1)/k){
            x[i]=1;
            cnt++;
            ans++;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(x[i]==1)cnt++;
        if(cnt<(i+k-1)/k){
            x[i]=1;
            ans++;
            cnt++;
        }
    }
    cout<<ans+1<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}