#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes;
void solve(){
    int n,k, q;
    cin>>n>>q;
    k=n;
    map<int,int> defactor,  defactork, factork, factor;
    for(auto& d:primes){
        if(d*d>k)break;
        while(k%d==0){
            if(defactork[d]!=0)defactor[defactork[d]+1]--;
            defactork[d]++;
            defactor[defactork[d]+1]++;
            k/=d;
        }
    }
    if(k>1){
        if(defactork[k]!=0)defactor[defactork[k]+1]--;
        defactork[k]++;
        defactor[defactork[k]+1]++;
    }
    factork = defactork;
    factor = defactor;
    for(int i=0; i<q; i++){
        int t;
        cin>>t;
        if(t==1){
            int a;
            cin>>a;
            for(auto& d:primes){
                if(d*d>a)break;
                while(a%d==0){
                    if(factork[d]!=0)factor[factork[d]+1]--;
                    factork[d]++;
                    factor[factork[d]+1]++;
                    a/=d;
                }
            }
            if(a>1){
                if(factork[a]!=0)factor[factork[a]+1]--;
                factork[a]++;
                factor[factork[a]+1]++;
            }
            bool f=  true;
            map<int,int> shf;
            for(auto [lool,num]:factor)
            {
                if(num==0)continue;
                int sh = lool;
                for(auto& d:primes){
                    if(d*d>sh)break;
                    while(sh%d==0){
                        sh/=d;
                        shf[d]+=num;
                    }
                }
                if(sh>1)shf[sh]+=num;
            }
            map<int,int> factort=factork;
            for(auto& [sheesh,nuu]:shf){
                if(factort[sheesh]<nuu){
                    f=false;
                }
                factort[sheesh]-=nuu;
            }
            if(f)cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            factor=defactor;
            factork=defactork;
        }
    }
    cout<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    vector<bool> prime(1e6+1,true);
    for(int i=2; i<=1e6; i++){
        if(!prime[i])continue;
        primes.push_back(i);
        for(int j=i*i; j<=1e6; j+=i){
            prime[j]=false;
        }
    }
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}