#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
using namespace std;


vector<int> x;
bool comp(int i, int k, int j){
    return (x[j]-x[i])*(k-i)>=(x[k]-x[i])*(j-i);
    // j is testing, k is greatest so far
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    x.resize(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<set<int>> s(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s[i].empty())s[i].insert(j);
            else if(comp(i,*s[i].rbegin(),j)) s[i].insert(j);
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans+=s[i].size();
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++){
        int i, b;
        cin>>i>>b;
        i--;
        x[i]+=b;
        // ones before
        for(int j=0; j<i; j++){
            auto it = s[j].lower_bound(i);
            bool rem = false;
            if((*it)==i){
                rem = true;
                it++;
            }
            else if(comp(j,(*prev(it)),i)){
                s[j].insert(i);
                rem = true;
                ans++;
            }
            while(rem&&it!=s[j].end()&&!comp(j, i, *it)){
                s[j].erase(it++);
                ans--;
            }
        }
        //ones after
        ans-=s[i].size();
        s[i].clear();
        for(int j=i+1; j<n; j++){
            if(s[i].empty())s[i].insert(j);
            else if(comp(i,*s[i].rbegin(),j)) s[i].insert(j);
        }
        ans+=s[i].size();
        cout<<ans<<"\n";
    }
}