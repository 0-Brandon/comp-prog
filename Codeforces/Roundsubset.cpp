#include <bits/stdc++.h>
using namespace std;
//doesn't work
signed main(){
    int n, k;
    int lol=200*26;
    cin>>n>>k;
    vector<vector<int>> cur(k+1, vector<int>(lol,INT_MIN));
    cur[0][0]=0;
    for(int i=0; i<n; i++){
        long long int a;
        int b=0, c=0;
        cin>>a;
        while(a%5==0)a/=5,b++;
        while(a%2==0)a/=2,c++;
        vector<vector<int>> nxt(k+1, vector<int>(lol,INT_MIN));
        for(int j=0; j<=k; j++){
            for(int l=0; l+b<lol; l++){
                nxt[j][l]=max(nxt[j][l], cur[j][l]);
                if(j<k)nxt[j+1][l+b]=max(nxt[j+1][l+b],cur[j][l]+c);
            }
        }
        cur=nxt;
    }
    int ans=0;
    for(int i=0; i<lol; i++){
        ans=max(ans,min(i,cur[k][i]));
    }
    cout<<ans<<"\n";
}