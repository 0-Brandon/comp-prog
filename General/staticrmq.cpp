#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<int> log(n);
    log[1]=0;
    for(int i=2; i<=n; i++){
        log[i]=log[i/2]+1;
    }
    int l = log[n];
    vector<int> x(n);
    vector<vector<int>> up(n,vector<int>(l));
    for(int i=0; i<n; i++){
        cin>>x[i];
        up[i][0]=x[i];
    }
    for(int j=1; j<l; j++){
        for(int i=0; i+(1<<j)-1<n; i++){
            up[i][j]=min(up[i][j-1],up[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        b--;
        int w=0;
        while(1<<(w+1)<=(b-a)+1)w++;
        cout<<min(up[a][w],up[b-(1<<w)+1][w])<<"\n";
    }
}