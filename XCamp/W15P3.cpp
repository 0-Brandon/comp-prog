#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    set<pair<int,int>> s0,s1;
    int ans = 0;
    //number modulo k, index
    for(int i=0; i<n; i++){
        if(a[i]=='1'&&b[i]=='0'){
            if(!s0.empty()){
                auto it = s0.lower_bound({i%k,-1});
                if(it==s0.end())it = s0.lower_bound({-1,-1});
                ans+=(i-it->second+k-1)/k;
                s0.erase(it);
            }
            else s1.insert({i%k,i});
        }
        if(a[i]=='0'&&b[i]=='1'){
            if(!s1.empty()){
                auto it = s1.lower_bound({i%k, -1});
                if(it==s1.end())it = s1.lower_bound({-1,-1});
                ans+=(i-it->second+k-1)/k;
                s1.erase(it);
            }
            else s0.insert({i%k,i});
        }
    }
    cout<<ans<<"\n";
}