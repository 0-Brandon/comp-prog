/*for each length
we store the number of times the most common substring of that length appears

then when we are considering l substrings
the answer is max(1 to n/l)*/
#include <bits/stdc++.h>
constexpr int p = 31;
constexpr int mod = 1e9+7;
using namespace std;

int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1, a= a*a%mod){
        if(b&1)ans=ans*a%mod;
    }
    return ans;
}
void solve(){
    int n, l, r;
    cin>>n>>l>>r;
    string s;
    cin>>s;
    vector<int> x(n+1);
    for(int l=1; l<=n; l++){
        map<int,int> cnt;
        int i=0, j=0;
        int h = 0;
        for(;j-i+1!=l;j++){
            h+=s[j]*exp(j,p-1);
            h%=mod;
        }
        for(;j<n;i++,j++){
            cnt[h]++;
            h-=s[i];
            if(h<0)h+=mod;
            h=h*exp(p,mod-2)%mod;
            h +=s[j]*exp(p,l-1)%mod;
            h%=mod;
        }
        for(auto& i:cnt)x[i.second]=max(x[i.second],l);
    }
    for(int i=1; i<=n; i++)x[i]=max(x[i],x[i-1]);
    for(int i=l; i<=r; i++){
        cout<<min(x[i],i)<<" ";
    }
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}



prefixes
if prefix of length l occurs k times 
l is potential answer for 1-k