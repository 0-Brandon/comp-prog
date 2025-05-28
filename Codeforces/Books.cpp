#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int l=0, r=0;
    int cur = x[0];
    int ans = 0;
    while(l<n&&r<n){
        if(cur<=k)ans = max(ans, r-l+1);
        if(cur>k){
            l++;
            if(l<=n)cur-=x[l-1];
        }
        else{
            r++;
            if(r<n)cur+=x[r];
        }
    }
    cout<<ans;
}