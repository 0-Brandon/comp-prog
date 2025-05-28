#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> x(n+1,0);
    vector<bool> bad(n,false);
    for(int i=0; i<k; i++){
        int a;
        cin>>a;
        bad[a]=true;
    }
    double as = 0;
    double bs = 0;
    vector<double> a(n);
    vector<double> b(n);
    for(int i=n-1; i>=0; i--){
        if(bad[i])a[i]=1,b[i]=0;
        else{
            a[i] = as/m;
            b[i] = bs/m+1;
        }
        as+=a[i];
        if(i+m<n)as-=a[i+m];
        bs+=b[i];
        if(i+m<n)bs-=b[i+m];
    }
    //0 = as[0] + bs
    if(abs(a[0]-1)<1e-6)cout<<"-1\n";
    else cout<<setprecision(15)<<b[0]/(1-a[0])<<"\n";
}