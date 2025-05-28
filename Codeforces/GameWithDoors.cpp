#include <bits/stdc++.h>

using namespace std;

void solve(){
    int l, r, i, j;cin>>l>>r>>i>>j;
    if(l>i||(l==i&&r>j)){
        swap(l,i);
        swap(r,j);
    }
    //l,r,i,j
    if(l<i&&r>j){
        cout<<j-i+2<<"\n";
    }
    else if(i<=r){
        int base = r-i;
        int ad = (l<i);
        ad+=(j>r);
        cout<<base+ad<<"\n";

    }
    else if(r<i)cout<<1<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}