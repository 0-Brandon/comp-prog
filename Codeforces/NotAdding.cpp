#include<bits/stdc++.h>

using namespace std;

int gcd(int x, int y){
    return !y?x:gcd(y,x%y);
}
const int MA = 1e6+5;
int main(){
    int n;
    cin>>n;
    vector<int> x(MA);
    for(int i=0; i<n; i++){
        int a;cin>>a;x[a]++;
    }
    int ans = 0;
    for(int i=1; i<MA; i++){
        if(x[i])continue;
        int c = 0;
        for(int j = i; j<MA; j+=i)if(x[j])c = gcd(c,j);
        if(c==i)ans++;
    }
    cout<<ans<<"\n";
}