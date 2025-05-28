#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hoofball.in","r",stdin);
    freopen("hoofball.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int ans = 1;
    for(int i=n-2; i>=0; i--){
        if(x[i]-x[i-1]>x[i+1]-x[i]){
            ans++;
        }
    }
    cout<<ans;
}