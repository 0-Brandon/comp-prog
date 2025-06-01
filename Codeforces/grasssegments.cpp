#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update


using namespace std;

using namespace __gnu_pbds;
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;
int main(){
    int n;
    cin>>n;
    vector<array<int,3>> x(n), y(n);
    for(int i=0; i<n; i++){
        cin>>x[i][1]>>x[i][2]>>x[i][0];
        for(int j=0; j<3; j++)y[i][j] = x[i][j];
    }
    vector<int> ord(n), ans(n);
    iota(ord.begin(),ord.end(),0);
    sort(ord.rbegin(),ord.rend(),[&](int i, int j){return x[i]<x[j];});
    sort(y.rbegin(),y.rend(),[&](auto i, auto j){return i[2]-i[1]<j[2]-j[1];});
    int cnt = 0;
    ordered_set r,l;
    for(auto& i:ord){
        while(cnt<n&&y[cnt][2]-y[cnt][1]>=x[i][0]){
            r.insert({y[cnt][2],cnt});
            l.insert({y[cnt][1],cnt});
            cnt++;
        }
        ans[i] = cnt;
        ans[i]-=r.order_of_key({x[i][1]+x[i][0], -1});
        ans[i]-=l.size()-l.order_of_key({x[i][2]-x[i][0], INT_MAX});
    }
    for(auto& i:ans)cout<<i-1<<"\n";
}