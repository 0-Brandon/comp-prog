#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
while(q--){
    int a,b;
    cin>>a>>b;
    cout<<upper_bound(x.begin(),x.end(),b)-lower_bound(x.begin(),x.end(),a)<<"\n";
}
}