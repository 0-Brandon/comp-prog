#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> ones;     
vector<int> pre;   
int n, m, zeros;
vector<int> gones(int k) {
    vector<int> chain;
    for(int i = 0; i < m; i++){
        int pos = ones[i]; 
        if(chain.empty()){
            if(pre[pos]>=k){ 
                chain.push_back(i);
            }
        } else{
            int last = chain.back();
            int lpos = ones[last];
            if(pre[pos]-pre[lpos+1]>=k) {
                chain.push_back(i);
            }
        }
    }
    while(!chain.empty()){
        int lidx = chain.back();
        int lpos = ones[lidx];
        if (pre[n] - pre[lpos+1]>=k) break;
        chain.pop_back();
    }
    return chain;
}
int val(int k, vector<int> &chain) {
    chain = gones(k);
    int r = chain.size();
    if (r == 0) return -1; 
    return r + (r + 1) * k;
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>s;
    pre.resize(n+1, 0);
    for (int i = 0; i<n; i++){
        pre[i+1]=pre[i]+(s[i]=='0');
    }
    zeros = pre[n];
    for (int i = 0; i < n; i++){
        if (s[i]=='1')
            ones.push_back(i);
    }
    m = ones.size();
    int aans = m;
    int kans = 0;
    vector<int> ans = gones(0);
    int lo = 0, hi = zeros;
    while(hi-lo>=100){
        int m1=lo+(hi-lo)/3;
        int m2=hi-(hi-lo)/3;
        vector<int> chain1, chain2;
        int f1=val(m1, chain1);
        int f2=val(m2, chain2);
        if(f1<f2)lo = m1;
        else hi = m2;
    }
    if(1LL*zeros*m<1e8)lo=0, hi = zeros;
    for(int k=lo; k<=hi; k++){
        vector<int> chain;
        int fVal = val(k, chain);
        if (fVal > aans) {
            aans = fVal;
            kans = k;
            ans = chain;
        }
    }
    cout<<aans<<"\n";
    string seq=string(kans, '0');
    for (int idx:ans) {
        seq.push_back('1');
        seq+=string(kans, '0');
    }
    cout<<seq<<"\n";
}
