#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef array<array<int,10>,10> mat;
vector<mat> t(10);
mat id;
mat mult(mat& x,mat& y){
    mat res;
    for(int i=0; i<10; i++)for(int j=0; j<10; j++)res[i][j] = 1e9;
    for(int i=0; i<10; i++)for(int k=0; k<10; k++)for(int j=0; j<10; j++)res[i][j] = min(res[i][j],x[i][k]+y[k][j]);
    return res;
}
struct Segtree{
    int n;
    vector<mat> e;
    Segtree(vector<mat>& a):n((int)a.size()),e(2*a.size()){
        for(int i=n; i<2*n; i++){
            e[i] = a[i-n];
        }
        for(int i=n-1; i>0; i--){
            e[i] = mult(e[i<<1],e[i<<1|1]);
        }
    }
    mat query(int l, int r){
        mat lans = id;
        mat rans;
        for(rans = e[r+=n],l+=n;l<r;l/=2,r/=2){
            if(l&1)lans = mult(lans,e[l++]);
            if(r&1)rans = mult(e[--r],rans);
        }
        return mult(lans,rans);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    for(int i=0; i<10; i++)for(int j=0; j<10; j++)id[i][j]=1e9;
    for(int i=0; i<10; i++)id[i][i]=0;i
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        x[i] = s[i]-'0';
    }
    for(int l=0; l<10; l++)for(int i=0; i<10; i++)for(int j=0; j<10; j++)t[i][j][l] = 1e9;
    for(int i=0; i<10; i++){
        for(int j=1; j<10; j++){
            t[i][j][j] = j;
            t[i][j][0] = 0;
        }
        t[i][0][i] = i;
    }
    vector<mat> dp(n);
    for(int i=0; i<n; i++)dp[i] = t[x[i]];
    Segtree seg(dp);
    for(int i=0; i<=n-k; i++){
        cout<<seg.query(i,i+k-1)[0][0]<<" ";
    }
    cout<<"\n";
}
