#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> o,z,ans(n);
    string s;
    cin>>s;
    for(int i=0; i<n; i++){
        int idx=z.size()+o.size();
        if(s[i]=='1'){
            if(z.empty())o.push_back(idx);
            else{
                idx=z.back();
                z.pop_back();
                o.push_back(idx);
            }
        }
        else{
            if(o.empty())z.push_back(idx);
            else{
                idx=o.back();
                o.pop_back();
                z.push_back(idx);
            }
        }
        ans[i]=idx;
    }
    cout<<o.size()+z.size()<<"\n";
    for(auto& i:ans)cout<<i+1<<" ";
    cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
}