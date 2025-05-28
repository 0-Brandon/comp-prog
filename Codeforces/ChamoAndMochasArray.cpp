#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int m=0;
    for(int i=0; i<n-1; i++){
        m=max(m,min(x[i],x[i+1]));
        if(i<n-2&&x[i+2] >= max(x[i],x[i+1]))m=max(m,max(x[i],x[i+1]));
        if(i>0&&x[i-1] >= max(x[i],x[i+1]))m=max(m,max(x[i],x[i+1]));
    }
    cout<<m<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}