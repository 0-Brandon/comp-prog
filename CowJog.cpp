#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    int n;
    cin>>n;
    vector<long long> cows(n);
    for(int i=0; i<n; i++){
        cin>>cows[i]>>cows[i];
    }
    long long groups = 0;
    long long cur = cows[n-1];
    for(int i=n-1; i>=0; i--){
        if(cows[i]<=cur){
            cur=cows[i];
            groups++;
        }
    }
    cout<<groups;
}