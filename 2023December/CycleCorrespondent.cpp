#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    vector<bool> hap(n);
    vector<int> a(k),b(k);
    vector<int> aocc(n,-1), bocc(n,-1);
    for(int i=0; i<k; i++){
        cin>>a[i];
        a[i]--;
        aocc[a[i]]=i;
        hap[a[i]]=true;
    }
    for(int i=0; i<k; i++){
        cin>>b[i];
        b[i]--;
        bocc[b[i]]=i;
        hap[b[i]]=true;
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!hap[i])ans++;
    }
    map<int,int> occ;
    for(int i=0; i<n; i++){
        if(!hap[i])continue;
        if(aocc[i]==-1||bocc[i]==-1)continue;
        int x = aocc[i]-bocc[i];
        x = (x+k)%k;
        occ[x]++;
    }
    int m = 0;
    for(auto [i,j]:occ)m = max(m,j);
    //reversed;
    reverse(b.begin(),b.end());
    for(int i=0; i<k; i++){
        bocc[b[i]]=i;
    }
    occ.clear();
    for(int i=0; i<n; i++){
        if(!hap[i])continue;
        if(aocc[i]==-1||bocc[i]==-1)continue;
        int x = aocc[i]-bocc[i];
        x = (x+k)%k;
        occ[x]++;
    }
    for(auto [i,j]:occ)m = max(m,j);
    cout<<ans+m<<"\n";
}