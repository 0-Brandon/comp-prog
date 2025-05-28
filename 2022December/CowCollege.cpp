#include <bits/stdc++.h>
using namespace std;
using ll=long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }  
    ll ans=0, ans2;
    sort(x.begin(),x.end());
    for(int i=0; i<n; i++){
        ll tuition = (n-i)*x[i];
        if(tuition>ans){
            ans=tuition;
            ans2=x[i];
        }
    }

    cout << ans <<" "<< ans2 <<"\n";
}