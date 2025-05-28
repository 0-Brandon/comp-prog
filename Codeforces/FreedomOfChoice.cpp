#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int m;
    cin>>m;
    vector<map<int,int>> x(m);
    map<int,vector<int>> contains;
    int sl=0, sr=0, sn=0;
    vector<int> L(m);
    vector<int> mtot(m);
    vector<int> tots(m,0);
    int total=0;
    for(int i=0; i<m; i++){
        int n, l, r;
        cin>>n>>l>>r;
        sn+=n,sl+=l,sr+=r;
        L[i]=l;
        total+=r;
        mtot[i]=r;
        vector<int> temp; 
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            temp.push_back(a);
            contains[a].push_back(i);
        }
        for(int j=0; j<n; j++){
            int a;
            cin>>a;
            x[i][temp[j]]=a;
            tots[i]+=a;
        }
    }
    if(sr-sl>sn){cout<<0<<"\n";return;}
    int ans = LLONG_MAX;
    for(int test=sl; test<=sr; test++){
        int cur = total;
        int mu=0;
        for(auto& i:contains[test]){
            cur-=mtot[i];
            mu+=max(0LL,L[i]-(tots[i]-x[i][test]));
            cur+=max(L[i],min(tots[i]-x[i][test],mtot[i]));
        }
        ans = min(ans, max(0LL,test-cur)+mu);
    }
    cout<<ans<<"\n";

}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}