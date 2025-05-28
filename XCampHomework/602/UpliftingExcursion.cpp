#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int m, L;
    cin>>m>>L;
    vector<int> x(2*m+1);
    vector<int> c(2*m+1);
    int sum = 0;
    for(int i=0; i<=2*m; i++)cin>>x[i];
    for(int i=0; i<=m; i++)sum+=x[i]*(i-m), c[i] = x[i];
    for(int i=m+1; i<=2*m; i++){
        int ch = min((L-sum)/(i-m),x[i]);
        c[i] =ch;
        sum+=ch*(i-m);
    }
    for(int i=0; i<m; i++){
        int ch = min((L-sum)/(m-i), x[i]);
        sum+=(ch)*(m-i);
        c[i]-=ch;
    }
    if(L-sum>m){cout<<"impossible\n";return 0;}
    int alr =0;
    vector<pair<int,int>> w;
    for(int i=0; i<=2*m; i++){
        alr+=c[i];
        if(i==m)continue;
        int h = min(x[i]-c[i],m*m);
        for(int j=1; j<=h; j*=2){
            w.push_back({j*(i-m),j});
            h-=j;
        }
        if(h)w.push_back({h*(i-m),h});
        h = min(c[i],m*m);
        for(int j=1; j<=h; j*=2){
            w.push_back({j*(m-i),-j});
            h-=j;
        }
        if(h)w.push_back({h*(m-i),-h});
    }
    vector<int> dp(2*m*m+1,-6e18);
    vector<int> ndp(2*m*m+1,-6e18);
    ndp[m*m]=0;
    for(int i=0; i<w.size(); i++){
        auto [lift, num] = w[i];
        for(int j=2*m*m; j>=0; j--){
            dp[j] = ndp[j];
            if(j-lift>=0&&j-lift<=2*m*m&&ndp[j-lift]!=-6e18){
                dp[j] = max(dp[j],ndp[j-lift]+num);
            }
        }
        swap(dp,ndp);
    }
    vector<int> cur =(w.size()%2==0)?ndp:dp;
    if(alr+cur[L+m*m-sum]<0){
        cout<<"impossible\n";
    }
    else cout<<alr+cur[L+m*m-sum];
}