#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n,q;
    cin>>n>>q;
    vector<int> h(n+1), g(n+1), j(n+1);
    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x==1){
            h[i]=h[i-1]+1;
            g[i]=g[i-1];
            j[i]=j[i-1];
        }
        if(x==2){
            h[i]=h[i-1];
            g[i]=g[i-1]+1;
            j[i]=j[i-1];
        }
        if(x==3){
            h[i]=h[i-1];
            g[i]=g[i-1];
            j[i]=j[i-1]+1;
        }
    }
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        cout<<h[r]-h[l-1]<<" "<<g[r]-g[l-1]<<" "<<j[r]-j[l-1]<<"\n";
    }
}