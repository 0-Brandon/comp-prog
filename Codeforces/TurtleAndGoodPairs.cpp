#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[s[i]]++;
    }
    while(mp.size()){
        auto it= mp.begin();
        while(it!=mp.end()){
            cout<<string(1,it->first);
            it->second--;
            if(it->second==0)mp.erase(it++);
            else it++;
        }
    }
    cout<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--)solve();
}