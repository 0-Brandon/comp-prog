#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
vector<int> primes;
int bpow(int a, int b){
    int ans = 1;
    for(a%=mod; b;b>>=1, a = (a*a)%mod){
        if(b&1)ans = (ans*a)%mod;
    }
    return ans;
}
void factor(int a,vector<pair<int,int>>& factors){
    for(int i=2; i*i<=a; i++){
        if(a%i==0){
            int c=0;
            while(a%i==0)a/=i,c++;
            factors.push_back({i,c});
        }
    }
    if(a>1)factors.push_back({a,1});
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    vector<bool> lol(2e5,true);
    for(int i=2; i<2e5; i++){
        if(!lol[i])continue;
        primes.push_back(i);
        for(int j=i*i; j<2e5; j+=i)lol[j]=false;
    }
    int n, q;
    cin>>n>>q;
    vector<map<int,int>> nums(n);
    map<int,multiset<int>> d;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        vector<pair<int,int>> factors;
        factor(a,factors);
        for(auto& [num,cnt]:factors){
            nums[i][num]=cnt;
            d[num].insert(cnt);
        }
    }
    int ans = 1;
    for(auto& [nu,i]:d){
        if(i.size()==n)ans = (ans * bpow(nu,*i.begin()))%mod;
    }
    for(int i=0; i<q; i++){
        int idx, a;
        cin>>idx>>a;
        idx--;
        vector<pair<int,int>> factors;
        factor(a,factors);
        for(auto&[num,cnt]:factors){
            if(d[num].size()==0){
                nums[idx][num]=cnt;
                d[num].insert(cnt);
                if(d[num].size()==n)ans = (ans * bpow(num, *d[num].begin()))%mod;
                continue;
            }
            int prevm = 0;
            if(d[num].size()==n)prevm=*d[num].begin();
            if(nums[idx][num]!=0)d[num].erase(d[num].find(nums[idx][num]));
            nums[idx][num]+=cnt;
            d[num].insert(nums[idx][num]);
            if(d[num].size()==n)ans = (ans * bpow(num, *d[num].begin()-prevm))%mod;
        }
        cout<<ans<<"\n";
    }
}