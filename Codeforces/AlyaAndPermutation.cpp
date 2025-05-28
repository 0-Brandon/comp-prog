#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x;
    int cur = 0;
    if(n%2==1){
        x.push_back(2);
        x.push_back(1);
        for(int i=3; i<=n; i++)x.push_back(i);
        cout<<n<<"\n";
        for(auto& i:x)cout<<i<<" ";cout<<"\n";

        for(int i=0; i<n; i++){
            if(i%2==0)cur&=x[i];
            else cur|=x[i];
        }
        assert(cur==n);
        return;
    }
    int a = (1<<(31-__builtin_clz(n)+1))-1;
    if(__builtin_popcount(n)==1){
        x.push_back(2);
        for(int i=4; i<=n-3; i++)x.push_back(i);
        x.push_back(1);
        x.push_back(3);
        x.push_back(n-2);
        x.push_back(n-1);
        x.push_back(n);
        cout<<a<<"\n";
        for(auto& i:x)cout<<i<<" ";cout<<"\n";
        for(int i=0; i<n; i++){
            if(i%2==0)cur&=x[i];
            else cur|=x[i];
        }
        assert(cur==a);
        return;
    }
    int b = (1<<(31-__builtin_clz(n)))-1;
    for(int i=1; i<b; i++)x.push_back(i);
    for(int i=b+1; i<=n-2; i++)x.push_back(i);
    x.push_back(n);
    x.push_back(n-1);
    x.push_back(b);
    cout<<a<<"\n";
    for(auto& i:x)cout<<i<<" ";cout<<"\n";
    for(int i=0; i<n; i++){
            if(i%2==0)cur&=x[i];
            else cur|=x[i];
        }
        assert(cur==a);
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
//even number -> next power of 2-1 except 4
//seem to switch between two patterns
// 6, 10, 14 are weird. they go 1,2,3,...n,a where a is some number 
// 8, 12, 16, 20, ... are like 1,2,3,4,5,6...n-2, n-3, n-1, n

//odd number -> itself
//2 1 ... n

