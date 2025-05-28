#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10000001;
signed main(){
    int t;
    cin>>t;
    array<int,N> res{};
    for(int i=1; i<N; i++){
        for(int j=2*i; j<N; j+=i){
            if((i&j)==i)res[j]++;
        }
    }
    for(int i=1; i<N; i++){
        res[i]+=res[i-1];
    }
    while(t--){
        int n;
        cin>>n;
        cout<<res[n]<<"\n";
    }
}
