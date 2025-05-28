#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, q;
    cin>>n>>q;
    vector<int> a(n),b(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i]--;
        b[a[i]]++;
    }
    for(int i=0; i<n; i++)m[b[i]]++;
    for(int i=0; i<q; i++){
        int c, d;
        int ans = 0;
        cin>>c>>d;c--,d--;
        m[b[a[c]]]--;
        if(m[b[a[c]]]==0)m.erase(b[a[c]]);
        b[a[c]]--;
        m[b[a[c]]]++;
        a[c] = d;
        m[b[d]]--;
        if(m[b[d]]==0)m.erase(b[d]);
        b[d]++;
        m[b[d]]++;
        int jnc = 1, knc = 1,jt=0,kt=0;
        if(1LL*n*q>=1e8)jnc=1,knc=1,jt=0,kt=0;
        for(int j=n-1; j>=n-100; j-=jnc){
            if(b[j]<=jt)continue;
            for(int k=0; k<=j-ans; k+=knc){
                if(b[k]<=kt)continue;
                if(b[j]+b[k]>=m.rbegin()->first){
                    ans = max(ans,abs(k-j));
                    break;
                }
            }
        }
        cout<<ans<<"\n";
    }
}

//you have an array b which is equal to the number of votes each cow gets
//now, you want to query
//what is the maximum distance between two indicies i and j such that b[i]+b[j]>=M
//b[i]>=M-b[j] 