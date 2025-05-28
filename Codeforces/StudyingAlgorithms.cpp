#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin>>n>>t;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int cur=0, ans = 0;
    for(int i=0; i<n&&cur<=t; i++){
        cur+=x[i];
        if(cur<=t)ans++;
    }
    cout<<ans;
}