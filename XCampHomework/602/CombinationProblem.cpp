#include <bits/stdc++.h>

using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int q,k;
    cin>>q>>k;
    int ma=0;
    vector<array<int,2>> qu(q);
    for(int i=0; i<q; i++){
        cin>>qu[i][0]>>qu[i][1];
        ma = max(ma,qu[i][0]);
    }
    vector<vector<int>> c(ma+1,vector<int>(ma+1,0));
    vector r(ma+2,vector<int>(ma+2,0));
    for(int i=0; i<=ma; i++){
        c[i][0]=1;
        for(int j=1; j<=i; j++){
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%k;
            r[i][j+1] = r[i][j]+(c[i][j]==0);
        }
    }
    //r[i][j] gives sum of C choose i up to j-1
    for(int i=0; i<q; i++){
        int ans = 0;
        for(int j=0; j<=qu[i][0]; j++){
            ans+=r[j][min(j,qu[i][1])+1];
        }
        cout<<ans<<"\n";
    }
}