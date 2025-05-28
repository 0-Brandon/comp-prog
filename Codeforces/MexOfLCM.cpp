#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    int n;cin>>n;
    set<int> tot;
    set<int> cur;
    for(int i=0; i<n;i++){
        int t; cin>>t;
        cur.insert(t);
        set<int> ne;
        for(auto& c:cur){
            int l = lcm(t,c);
            if(l<=n*n+1)ne.insert(l);
        }
        for(auto& li:ne){
            tot.insert(li);
        }
        swap(ne,cur);
    }
    int i=1;
    for(auto& c:tot){
        if(c!=i){cout<<i<<" "<<"\n";return;}
        i++;
    }
    cout<<i<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}