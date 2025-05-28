#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 1e9+7;
vector<int> f{1,-1,1};
struct ev{
    int i, row;
    bool s;
    ev(int a, int b, int c):i(a),row(b),s(c){}
    bool operator<(ev o){
        return i<o.i;
    }
};
struct MA{
    vector<vector<int>> e;
    MA():e{{0,0,0},{0,0,0},{0,0,0}}{}
    MA(vector<vector<int>> x):e(x){}
    MA operator * (MA o){
        MA ret;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                for(int k=0; k<3; k++){
                    ret.e[i][k]+=((e[i][j]%mod) * (o.e[j][k]%mod))%mod;
                    ret.e[i][k]%=mod;
                }
            }
        }
        return ret;
    }
};
MA exp(MA a, int b){
    MA ret;
    ret.e[0][0]=ret.e[1][1]=ret.e[2][2]=1;
    for(;b;b>>=1,a=a*a){
        if(b&1)ret=ret*a;
    }
    return ret;
}
signed main(){
    int n, m;
    cin>>n>>m;
    vector<ev> x;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--;
       // b--,c--;
        x.emplace_back(b,a,1);
        x.emplace_back(c+1,a,0);
    }
    sort(x.begin(),x.end());
    x.emplace_back(m+1,0,1);
    vector<vector<int>> lol{{1,1,0},{1,1,1},{0,1,1}};
    MA t(vector<vector<int>>{{1,1,0},{1,1,1},{0,1,1}});
    if(x[0].i==1)f={0,0,0};
    vector<int> cnt(3,0);
    for(int id=0; id<x.size(); id++){
        //multiply lsat segment
        if(f==vector<int>{0,0,0})break;
        int l = 1;
        if(id!=0)l = x[id-1].i;
        MA shesh = exp(t,x[id].i-l);
        vector<int> nf(3,0);
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                nf[i]=(nf[i]+(f[j]*shesh.e[i][j]));
                while(nf[i]<0)nf[i]+=mod;
                nf[i]%=mod;
            }
        }
        f=nf;
        //modify t for next segment
        if (x[id].s){
            t.e[x[id].row] = {0,0,0};
            cnt[x[id].row]++;
        }
        else {
            if(--cnt[x[id].row]==0)t.e[x[id].row]= lol[x[id].row];
        }
        
    }
   cout<<f[1]<<"\n";
}