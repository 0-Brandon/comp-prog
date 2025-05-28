#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    map<int,vector<pair<int,int>>> g;
    for(int i=0; i<n; i++){
        int s=0;
        for(int j=i; j>=0; j--){
            s+=x[j];
            g[s].push_back({j,i});
        }
    }
    int m = 0;
    vector<pair<int,int>> ans;
    for(auto& i:g){
        vector<pair<int,int>> cur;
        int s=0;
        int r=-1;
        for(auto& in:i.second){
            if(in.first>r){
                s++;
                cur.push_back(in);
                r=in.second;
            }
        }
        if(s>m){
            m=s;
            ans=cur;
        }
    }
    cout<<m<<"\n";
    for(auto& i:ans)cout<<i.first+1<<" "<<i.second+1<<"\n";
}