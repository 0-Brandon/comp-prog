#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n+1), s(n+1);
    for(int i=1; i<=n; i++){
        s[i]=i;
        cin>>x[i];
    }
    sort(s.begin(),s.end(),[&](int i, int j){return x[i]>x[j];});
    vector<int> chain;
    vector<pair<int,int>> ans;
    int l=-1;
    for(auto& i:s){
        if(i==0)continue;
        chain.push_back(2*i);
        if(l!=-1)ans.push_back({chain.back(),l});
        l=2*i;
    }
    //chain now contains n indices, with greatest chain on left
    for(int i=0; i<n; i++){
        if(i+x[chain[i]/2]>=chain.size()){
            ans.push_back({chain[i]-1,chain.back()});
            chain.push_back(chain[i]-1);
        }
        else{
            ans.push_back({chain[i+x[chain[i]/2]-1],chain[i]-1});
        }
    }
    for(auto& [i,j]:ans){
        cout<<i<<" "<<j<<"\n";
    }
}