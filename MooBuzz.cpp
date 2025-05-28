#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("moobuzz.in","r",stdin);
    freopen("moobuzz.out","w",stdout);
    int n;
    cin>>n;
    int group = (n-1)/8;
    int re=n%8;
    int j = 0;
    int i;
    for(i=15*group;j<re;i++){
        if(i%3!=0&&i%5!=0){
            j++;
        }
        if(j==re) break;
    }
    if(re==0) cout<<i+14;
    else cout<<i;
}