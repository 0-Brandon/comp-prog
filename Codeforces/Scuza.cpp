#include <bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long int> x(n+1);
        x[0]=0;
        for(int i=1; i<=n; i++){
            int temp;
            cin>>temp;
            x[i]=x[i-1]+temp;
        }
        for(int i=0; i<q; i++){
            long long int j;
            cin>>j;
            cout<<x[upper_bound(x.begin(),x.end(),j)-x.begin()]<<" ";
        }
        cout<<"\n";
    }
}