#include <bits/stdc++.h>

using namespace std;

int main(){
    double f, m, n;
    cin>>f>>m>>n;
    vector<pair<int,pair<int,int>>> x(n);
    for(int i=0; i<n; i++){
        x[i].first = i+1;
        cin>>x[i].second.first>>x[i].second.second;
    }
    vector<int> ans;
    sort(x.begin(), x.end(), [&](auto i, auto y){return y.second.first/y.second.second<i.second.first/i.second.second;});
    for(int i=0; i<n; i++){
        if((f+x[i].second.first)/(m+x[i].second.second)>f/m){
            f+=x[i].second.first;
            m+=x[i].second.second;
            ans.push_back(x[i].first);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()==0)cout<<"NONE";
    else
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    
}