#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<int> x(100), y(100);
    int j = 0;
    for(int i=0; i<n; i++){
        int temp, temp2;
        cin>>temp>>temp2;
        int p = j;
        for(; j<p+temp; j++){
            x[j] = temp2;
        }
    }
    j = 0;
    int ans = 0;
    for(int i=0; i<m; i++){
   int temp,temp2;
        cin>>temp>>temp2;
        int p = j;
        for(; j<p+temp; j++){
            y[j] = temp2;
        }
    }
    for(int i=0; i<100; i++){
        ans = max(ans, y[i]-x[i]);
    }
    cout<<ans;
}