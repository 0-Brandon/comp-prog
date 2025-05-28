#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> x(1001);
    for(int i=0; i<n; i++){
        int s, t, b;
        cin>>s>>t>>b;
        x[s]=b;
        x[t]=-b;
    }
    int sum = 0;
    int ans = 0;
    for(int i=0; i<1001; i++){
        sum+=x[i];
        ans = max(ans, sum);
    }
    cout<<ans;
}