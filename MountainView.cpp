#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("mountains.out","w",stdout);
    freopen("mountains.in","r",stdin);
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x.push_back({a-b,a+b});
    }
    sort(x.begin(),x.end(),[&](pair<int,int>& a, pair<int,int>& b){return a.first<b.first||(a.first==b.first&&a.second>b.second);});
    int ans=0, m = 0;
    for(auto& i:x){
        auto& [a,b] = i;
        if(b<=m) ;
        else ans++;
        m = max(m,b);
    }
    cout<<ans;
}