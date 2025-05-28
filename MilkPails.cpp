#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
int x,y,m;
int ans = 0;
cin>>x>>y>>m;
for(int i = 0; i*x<m; i++){
    int temp = ((m-(i*x))/y)*y+i*x;
    ans = max(ans, temp);
}
cout<<ans;
}