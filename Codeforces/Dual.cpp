#include <bits/stdc++.h>
//broken
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> x(n);
    int pos = 0, neg = 0;
    int poss=0,negs=0;
    int ma = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        if(abs(x[i])>abs(x[ma])){
            ma=i;
        }
        if(x[i]<0) neg++;
        if(x[i]>0) pos++;
    }
    if(neg+5<=12)poss=5;
    if(pos+5<=12)negs=5;
    int c = n-1+poss+neg;
    if(c<=31){
        cout<<c<<"\n";
        int m = 0;
        for(int i=0; i<n; i++){
            if(x[i]>x[m]){
                m=i;
            }
        }
        for(int i=0; i<poss; i++){
            cout<<m+1<<" "<<m+1<<"\n";
        }
        for(int i=0; i<n; i++){
            if(x[i]<0)cout<<i+1<<" "<<m+1<<"\n";
        }
        for(int i=1; i<n; i++){
            cout<<i+1<<" "<<i<<"\n";
        }
    }
    else{
        cout<<n-1+negs+pos<<"\n";
        int m = 0;
        for(int i=0; i<n; i++){
            if(x[i]<x[m]){
                m=i;
            }
        }
        for(int i=0; i<negs; i++){
            cout<<m+1<<" "<<m+1<<"\n";
        }
        for(int i=0; i<n; i++){
            if(x[i]>0)cout<<i+1<<" "<<m+1<<"\n";
        }
        for(int i=n-1; i>=1; i--){
            cout<<i<<" "<<i+1<<"\n";
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}