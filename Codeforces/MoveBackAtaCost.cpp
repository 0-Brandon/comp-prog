//max number of ops is n?
// since its not optimal to ever add twice 
//best array is non decreasing
//if theres an element after thats less, we will add to this one
//the ones between are higher, we will add in ascending order
//the suffix mins stay
//the other ones are al plus one, add to end in increasing order

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    set<int> s;
    for(int i=0; i<n; i++){
        cin>>x[i];
        s.insert(i);
    }
    multiset<int> ans;
    vector<int> aa;
    int m = 1e9;
    for(int i=n-1; i>=0; i--){
        if(x[i]<=m)ans.insert(x[i]),aa.push_back(x[i]),s.erase(i);
        m = min(m,x[i]);
    }
    reverse(aa.begin(),aa.end());
    vector<int> lef;
    lef.push_back(1e9);
    for(auto& i:s)lef.push_back(x[i]+1);
    sort(lef.begin(),lef.end());
    for(auto it = lower_bound(aa.begin(),aa.end(),lef[0]+1); it!=aa.end();it++){
        lef.push_back(*it+1);
    }
    sort(lef.begin(),lef.end());
    while(aa.back()>lef[0])aa.pop_back();
    lef.pop_back();
    for(auto&i:lef)aa.push_back(i);
    for(auto& i:aa)cout<<i<<" ";cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}