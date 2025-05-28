#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> back(n);
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]--;
        back[a[i]].push_back(i);
    }
    vector<int> c(n);
    for(int i=0; i<n; i++)cin>>c[i];
    int ans = 0;
    for(int i=0; i<n; i++)if(a[a[i]] !=a[i])ans+=c[i];
    //dp on the edges we add back
    //sort the nodes smallest to largest in terms of savings
    dp[i] is the minimum cost we can get considering up to ith node
    we either 
    cout<<ans<<"\n";
}