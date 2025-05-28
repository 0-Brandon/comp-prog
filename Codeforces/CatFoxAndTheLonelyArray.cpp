#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 1;
    for(int i=0; i<30; i++){
        int l = -1;
        int cur = 0;
        for(int j=0; j<n; j++){
            if((x[j]>>i)&1)cur = max(cur,j-l), l = j;
        }
        if(l!=-1)cur = max(cur,n-l);
        ans = max(ans,cur);
    }
    cout<<ans<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--){solve();}
}