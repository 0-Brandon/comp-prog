#include <bits/stdc++.h>

using namespace std;

int exp(int a, int b){
    int ans = 1;
    for(;b;b>>=1,a*=a){
        if(b&1)ans*=a;
    }
    return ans;
}
int main(){
    vector<int> lp(1e7+1,0);
    vector<int> p;
    for(int i=2; i<=1e7; i++){
        if(lp[i]==0){
            lp[i]=i;
            p.push_back(i);
        }
        for(int j=0; i*p[j]<=1e7;j++){
            lp[i*p[j]]=p[j];
            if(p[j]==lp[i])break;
        }
    }
    int n;
    cin>>n;
    vector<int> ans1(n,-1),ans2(n,-1);
    for(int i=0; i<n; i++){
        int lol;
        cin>>lol;
        int a = lol;
        map<int,int> factors;
        while(a>1){
            factors[lp[a]]++;
            a/=lp[a];
        }
        if(factors.size()>=2){
            int aa = exp(factors.begin()->first,factors.begin()->second);
            ans1[i] = aa;
            ans2[i] = lol/aa;
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<n; i++){
        cout<<ans2[i]<<" ";
    }
}