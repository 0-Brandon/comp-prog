#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,bool>> x(2*n);
    for(int i=0; i<n; i+=2){
        cin>>x[i].first;
        x[i].second = true;
        cin>>x[i+1].first;
        x[i+1].second=false;
    }
    sort(x.begin(), x.end());
    
}