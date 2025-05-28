#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin>>n;
    int i=0,j=0;
    vector<vector<int>> ans(2,vector<int>(n));
    int num = 2*n-1;
    while(num>0){
        if(i>ans.size()||j>ans[0].size())cout<<i<<" "<<j;
        ans[i][j]=num;
        j++;
        i=!i;
        if(j==n-1&&i==1)j=0;
        num--;
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            if(!(i==1&&j==n-1))cout<<ans[i][j]<<" ";
        }
        if(i==0)cout<<"\n";
    }
    cout<<2*n<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}