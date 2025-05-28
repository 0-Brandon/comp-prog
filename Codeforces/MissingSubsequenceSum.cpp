#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> ans(20);
    for(int i=0; i<ans.size(); i++)ans[i] = 1<<i;
    int b = 31-__builtin_clz(k);
    //replace functionality of forbidden one
    ans.push_back(k|(1<<(b+1)));
    ans.push_back(k|(1<<(b+1)));
    if(1<<b==k){
        ans[b]++;
        cout<<ans.size()<<"\n";;
        for(auto& i:ans)cout<<i<<" ";cout<<"\n";return;
    }
    //replace functionality of one we changed
    // same thing, just 1+(changed bit)
    ans.push_back(1<<b|(1<<(b+1)));
    ans.push_back(1<<b|(1<<(b+1)));
    //
    ans.push_back(k+1);
    ans[b] = k-((1<<b));
    cout<<ans.size()<<"\n"; 
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
