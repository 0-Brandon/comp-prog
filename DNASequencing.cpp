#include <bits/stdc++.h>
using namespace std;
int check(string s, string x, string y){
    for(int i=0; i<s.size(); i++){
        if(y[i]!=s[i]&&y[i]!=x[i]) return 0;
    }
    return 1;
}
int main(){
    int m,f;
    cin>>m>>f;
    vector<string> males(m);
    vector<string> females(f);
    vector<vector<int>> ans(m, vector<int>(f));
    for(int i=0; i<m; i++){
        cin>>males[i];
    }
    for(int i=0; i<f; i++){ 
        cin>>females[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<f; j++){
            for(int k=0; k<m; k++){
                if(k==i)continue;
                ans[i][j]+=check(males[i], females[j], males[k]);
            }
            for(int k=0; k<f; k++){
                if(k==j)continue;
                ans[i][j]+=check(males[i], females[j], females[k]);
            }
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<f; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}