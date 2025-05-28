#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> s(n),v(n),c(m);
    for(int i=0; i<n; i++){
        cin>>s[i]>>v[i];
    }
    for(int i=0; i<m; i++) cin>>c[i];
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int i, int j){return v[i]==v[j]?s[i]>s[j]:v[i]>v[j];});
    sort(c.rbegin(),c.rend());
    int ans = 0;
    int p = 0;
    for(auto& i:ord){
        if(p==m||c[p]<s[i])continue;
        ans++; 
        p++;
    }
    cout<<ans<<"\n";
}