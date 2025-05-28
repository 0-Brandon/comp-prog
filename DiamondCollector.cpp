#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 1;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(x[j]-x[i] <= k && x[j]>=x[i]) count++;
        }
         ans = max(count, ans);
    }
    cout<<ans;
}