#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    set<long long int> nums;
    for(long long int i=2; i<=1e6; i++){
        long long int acc = 1LL+i+i*i;
        long long int p = 1LL*i*i;
        while(acc<=1e18){
            nums.insert(acc);
            if(1e18/i<p)break;
            p*=i;
            if(1e18-p<acc)break;
            acc+=p;
        }
    }
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        if(n<7){cout<<"no\n";continue;}
        long long int te=sqrt(n-1);
        if(te*(te+1)==n-1||(te-1)*te==n-1)cout<<"YES\n";
        else if(nums.count(n))cout<<"YES\n";
        else cout<<"NO\n";
    }
}