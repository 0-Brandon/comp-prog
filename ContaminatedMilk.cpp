#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, d, s;
    cin>>n>>m>>d>>s;
    vector<vector<int>> drank(d,vector<int>(3));
    vector<pair<int,int>> sick(s);
    for(int i=0; i<d; i++){
        cin>>drank[i][1]>>drank[i][2]>>drank[i][0];
    }
    for(int i=0; i<s; i++){
        cin>>sick[i].second>>sick[i].first;
    }
    sort(sick.begin(),sick.end());
    sort(drank.begin(),drank.end());
    int sidx = sick[0].first;
    int ans =0;
    for(int j=1; j<=50; j++){
        vector<bool> x(n,false);
        bool flag = false;
        int count = 0;
        for(int i=0; i<d; i++){
            if(sidx==i){
                if(!x[sick[sidx++].second]) {
                    flag = true;
                    break;
                }
            }
            if(drank[i][2]==j){
                x[drank[i][1]]=true;
                count++;
            }
        }
        if(!flag){
            ans = max(ans,count);
        }
    }
    cout<<ans;
}