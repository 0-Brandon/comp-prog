
/*

composite means 0 guaranteed...
two cases:
if j>i-j
then it creates a range from (i-j) to i, length is j... so
it includes once j and once every divisor so it is 0
if j<i-j
range is length (i-j), so it includes j once and all of its divisors once

prime:
two cases:
if j>i-j:
range from (i-j) to i, length is j. includes j once, but no other multiple
thus, non 0

if j<i-j:
range from i-j to i, length is j. because length is j, it includes j once

we end up multiplying a range from i-j to i of length j
if j is composite, this range will divide j once and all of j's divisors once, so 0
if j is prime, this range will have one multiple of j...
!!!!!!! however, that multiple
could be a multi-multiple such as j^2 in which case it would be 0



if j>i-j ie j>i/2 then we only divide by j once, we end up with 

i-j...i-j+1... j-1...j+2...i-1...ie

if j can be broken down into smaller divisors, we may potentially find them in 
the remaining numbers...
if it is prime and greater than i-j, there exists no other 
multiple of j less than i, so this answer is non 0

we seem to have a continuous range of i-j to j-1, and then j-1 to i 
so every number from 1 to max(length of these 2 ranges) is a divisor
 
if j<i-j ie j<i/2 then we end up with 

i-j, i-j+1, i-1, i / j 

we can guarantee that there is one multiple of j in this range...
if we can break it down further, then we may potentially be 0
otherwise... if its prime, there is only one multiple. thus, it is non 0


*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int mod = 1e9+7;
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int N = 1e6+10;
    vector<int> primes;
    vector<bool> ip(N, true);
    for(int i=2; i<N; i++){
        if(!ip[i])continue;
        primes.push_back(i);
        for(int j=i*i; j<N; j+=i){
            ip[j]=false;
        }
    }
    vector<int> ans(N,0);
    for(auto& p:primes){
        int c = -1;
        for(int i=p; i<N; i+=p){
            if(c==-1)c = p-1, ans[i]+=p-1;
            else ans[i] += -1;
            c--;
        }
    }
    int c=2;
    for(int j=4; j<N; j+=4){
        ans[j]+=c;
        if(c==2)c=-2;
        else c=2;
    }
    for(int i=1; i<N; i++){
        ans[i]=(ans[i]+ans[i-1])%mod;
    }
    for(int i=1; i<N; i++){
        ans[i]=(ans[i]+ans[i-1])%mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}
/*
c(i,78,498) from i to n

for(int i=0; i<n; i++){
    for(auto& j:primes){
        if(j>i)break;
        C(i,j)%j
    }
}
for(auto& i:primes){
    for(int j=i; j<n; j++){
        ans[j]+=i-1-((j-i)%(i*i)/i);
    }
}
1 2 3 4 5 6 7 8 9 10 11 12 13 14 
*/
//1 3 4 8 10 