//wrong 
#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n,k;
    cin>>n>>k;
    if(k&1){
        for(int i=0; i<k; i++){
            cout<<n<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i=0; i<k-2; i++){
            cout<<n<<" ";
        }
        if((n^(1LL<<(63-__builtin_clzll(n))))==0){
            cout<<0<<" "<<n<<"\n";
            return;
        }
        long long a = (1LL<<(63-__builtin_clzll((n^(1LL<<(63-__builtin_clzll(n)))))))+(1LL<<(63-__builtin_clzll((n^(1LL<<(63-__builtin_clzll(n)))))))-1;
        cout<<a<<" "<<(n^a)<<"\n";
    }
}
int main(){
    int t;cin >> t;
    while (t--)
    {
        solve();
    }
}