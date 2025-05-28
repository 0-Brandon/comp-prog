#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> x(n);
        int ma=INT_MAX,mi=0;
        for(int i=0; i<n; i++){
            cin>>x[i];
            ma = min(ma,x[i]);
            mi = max(mi,x[i]);
        }
        cout<<(mi-ma)*(n-1)<<"\n";
    }
}