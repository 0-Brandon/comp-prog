#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod = 1e9+7;

signed main(){
    int n, a, b, d;
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>d>>a>>b;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    set<pair<int, int>> s;
    for(int i=0; i<n; i++){
        s.insert({-x[i], i});
    }
    int k = 0; 
    bool equal = false;
    while(k<d && !equal){
        vector<int> topa;
        auto it = s.begin();
        for(int i=0; i<a; i++, it++){
            topa.push_back(it->second);
        }
        for(int idx:topa){
            s.erase({-x[idx], idx});
            x[idx]++;
            s.insert({-x[idx], idx});
        }
        vector<int> topb;
        it = s.begin();
        for(int i=0; i<b; i++, it++){
            topb.push_back(it->second);
        }
        for(int idx:topb){
            s.erase({-x[idx], idx});
            x[idx]--;
            s.insert({-x[idx], idx});
        }
        k++;
        if(k<d){
            vector<int> values;
            it = s.begin();
            for(int i=0; i <= a; i++, it++){
                values.push_back(-it->first);
            }
            if(values[a-1]==values[0] &&(a==n||values[a-1]>values[a])){
                equal = true;
            }
        }
    }
    if(k < d && equal){
        int rem = d-k;
        int periods = rem/a;
        int extra = rem%a;
        int increase =(a-b)*periods;
        vector<int> topa;
        auto it = s.begin();
        for(int i=0; i<a; i++, it++){
            topa.push_back(it->second);
        }
        for(int idx:topa){
            x[idx] += increase;
        }
        s.clear();
        for(int i=0; i<n; i++){
            s.insert({-x[i], i});
        }
        for(int d=0; d<extra; d++){
            topa.clear();
            it = s.begin();
            for(int i=0; i<a; i++, it++){
                topa.push_back(it->second);
            }
            for(int idx:topa){
                s.erase({-x[idx], idx});
                x[idx]++;
                s.insert({-x[idx], idx});
            }
            vector<int> topb;
            it = s.begin();
            for(int i=0; i<b; i++, it++){
                topb.push_back(it->second);
            }
            for(int idx:topb){
                s.erase({-x[idx], idx});
                x[idx]--;
                s.insert({-x[idx], idx});
            }
        }
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        sum +=x[i]*x[i]%mod;
        sum%=mod;
    }
    cout<<sum<<"\n";
}