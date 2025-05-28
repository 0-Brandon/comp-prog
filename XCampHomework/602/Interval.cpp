#include <bits/stdc++.h>
#define bint long long
using namespace std;
bint mul(bint a, bint b, bint mod){
    return (__int128)a*b%mod;
}
bint f(bint a, bint b, bint mod){
    return (mul(a,a,mod)+b)%mod;
}
bint rho(bint n, bint a, bint c){
    long long x = a,g=1,q=1,xs,y;
    bint m = 128;
    bint l = 1;
    while(g==1){
        y=x;
        for(bint i=1; i<l; i++)x = f(x,c,n);
        bint k=0;
        while(k<1&&g==1){
            xs = x;
            for(bint i=0; i<m&&i<l-k; i++){
                x = f(x,c,n);
                q = mul(q,abs(x-y),n);
            }
            g = gcd(q,n);
            k+=m;
        }
        l*=2;
    }
    if (g==n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}
bint exp(bint a, bint b, bint mod){
    bint ans = 1;
    for(;b;b>>=1,a=a*a%mod){
        if(b&1)ans = ans*a%mod;
    }
    return ans;
}
bool cc(bint n, bint a, bint d, bint s) {
    bint x = exp(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (bint r = 1; r < s; r++) {
        x = mul(x,x,n);
        if (x == n - 1)
            return false;
    }
    return true;
};
bool prime(bint n){
    if(n<2)return false;
    bint r = 0, d = n-1;
    while((d&1)==0)d>>=1,r++;
    for (bint a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (cc(n, a, d, r))
            return false;
    }
    return true;
}
vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
map<bint,bint> mp;
void factorize(int m,int b, int c){
    if(m<=100){
        for(auto& i:primes){
            while(m%i==0){
                m/=i;
                mp[i]++;
            }
        }
        return;
    }
    while(m!=1){
        bint d = rho(m,b,c);
        cout<<d<<" ";
        m/=d;
        if(!prime(d)){
            factorize(d,b+2, c+1);
        }else{
            mp[d]++;
        }
    }
}
//1e4 operations total
void solve(){
    bint m; cin>>m;
    int om = m;
    if(prime(m)){
        cout<<"NIE\n";
        return;
    }
    factorize(m,2,1);
    vector<bint> tot;
    for(auto& [a,b]:mp){
        cout<<a<<" "<<b<<" ";
        tot.push_back(exp(a,b,1e18));
    }
    sort(tot.begin(),tot.end());
    if(tot.back()-tot[0]>1e3){
        cout<<"NIE\n";
        return;
    }
    bint l = 1;
    for(bint i=tot[0]; i<=tot.back(); i++){
        l = lcm(l,i);
    }
    if(l!=om){
        cout<<"NIE\n";
        return;
    }
    bint a = tot[0], b = tot.back();
    for(bint i=tot[0]; tot[0]-i<=2000&&i>0; i--){
        if(om%i==0)a = i;
        else break;
    }
    cout<<a<<" "<<b<<"\n";
}
signed main(){
    bint t;
    cin>>t;
    while(t--){
        solve();
        mp.clear();
    }
}