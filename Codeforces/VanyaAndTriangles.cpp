#include <bits/stdc++.h>
#define int long long
using namespace std;
//doesn't work because general form for line isn't unique
//i.e. some lines give -2y=0 while others are 150y=0, resulting in being counted as different
signed main(){
    int n;
    cin>>n;
    vector<pair<int,int>> x;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x.push_back({a,b});
    }
    map<array<int,3>,set<int>> lines;
    vector<int> c3(n,0);
    c3[3] = 1;
    for(int i=4; i<=n; i++){
        c3[i] = c3[i-1]*i/(i-3);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            //ax+by+c==0
            array<int,3> t = {
                x[j].second-x[i].second,
                x[i].first-x[j].first,
                x[j].first*x[i].second-x[i].first*x[j].second
                };
                cout<<x[i].first<<" "<<x[i].second<<" "<<x[j].first<<" "<<x[j].second<<" "<<t[0]<<" "<<t[1]<<" "<<t[2]<<"\n";
            lines[t].insert(i);
            lines[t].insert(j);
        }
    }
    int ans = c3[n];
    for(auto& [l,i]:lines){
        ans-=c3[i.size()];
    }
    cout<<ans<<"\n";
}