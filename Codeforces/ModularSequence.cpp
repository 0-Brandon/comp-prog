#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> dp(200005,{INT_MAX-1  ,0});
void solve(){
    int n, x, y, s;
    cin>>n>>x>>y>>s;
    s-=(x%y)*n;
    s-=(x/y)*y;
    if(s<0||s%y!=0){cout<<"NO\n";return;}
    s/=y;
    int curs = s;
    int start = x/y;
    for(int i=0; i<n; i++){
        if(dp[curs].first<n-i){  
            cout<<"YES\n";
            int ans = 0;
            for(int j=0; j<=i; j++){
                cout<<x+(j)*y<<" ";
                ans++;
            }
            while(curs){
                for(int j=0; j<=dp[curs].second; j++){
                    cout<<x%y+y*j<<" ";
                    ans++;
                }
                curs-=dp[curs].second*(dp[curs].second+1)/2;
            }
            while(ans<n){cout<<x%y<<" "; ans++;}
            cout<<"\n";
            return;
        }
        start++;
        curs-=start;
        if(curs<0)break;
    }
    cout<<"NO\n";
}
signed main(){
    dp[0]={0,0};
    for(int i=0; i<dp.size(); i++){
        for(int j=1; i+j*(j+1)/2<dp.size(); j++){
            int v = j*(j+1)/2+i;
            if(dp[i].first+j+1<dp[v].first)dp[v]={dp[i].first+j+1,j};
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}