#include <bits/stdc++.h>

using namespace std;




void solve(){
    int n;
    cin>>n;
    int ans = 0;
    for(int i=0; i<n; i++){
        int s = 0;
        for(int j=1; j<=n; j++){
            if(j>i){
                s+=(n-(j-i)+1)*j;
            }else{
                s+=j*j; 
            }
        }
        int numrev = n-i;
        int sub = 0;
        if(numrev%2==0)sub=(n-numrev/2)*(n-numrev/2+1);
        else sub = (n-numrev/2)*(n-numrev/2);
        ans=max(ans,s-sub);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}