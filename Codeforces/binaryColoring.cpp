#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a;cin>>a;
    vector<int> x(32);
    cout<<31<<"\n";
    int c = 0;
    vector<int> ans(31);
    for(int i=0; i<31; i++){
        x[i] = (a>>i)&1;
    }
    for(int i=0; i<32; i++){
        if(x[i]==0)continue;
        if(ans[i]){
            ans[i+1]=1;
            ans[i]=0;
        }else if(i>0&&ans[i-1]==1){
            ans[i-1]=-1;
            ans[i]=0;
            ans[i+1]=1;
        }
        else{
            ans[i]=1;
        }
    }
    for(auto& i:ans)cout<<i<<" ";
    cout<<"\n";
}
signed main(){
    int t;cin>>t;
    while(t--)solve();
}