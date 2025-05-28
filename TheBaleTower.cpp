#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<pair<int,int>> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
    }
    for(int i=0; i<pow(2,n); i++){
        vector<int> temp;
        for(int k=0; k<n; k++){
            if((1<<k)&i){
                temp.push_back(k);
            }
        }
        for(int i=0; i<n; i++){
            x[temp[i]]
        }
    }

}