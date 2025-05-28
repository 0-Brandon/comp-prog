#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    bool rev = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]--;
        if(x[i]==0&&i%2==0)rev=1;
    }
    if(rev)reverse(x.begin(),x.end());
    //1 is on a odd number
    vector<int> pos(n);
    vector<int> ev;
    vector<int> ans(n);
    for(int i=0; i<n; i++){
        pos[x[i]]=i;
        ans[i] = n-x[i];
        if(i%2==0)ev.push_back(x[i]);
    }
    sort(ev.begin(),ev.end());
    for(auto& i:ev){
        swap(ans[pos[i]],ans[pos[0]]);
    }
    if(rev)reverse(ans.begin(),ans.end());
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}