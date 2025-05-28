#include <bits/stdc++.h>

using namespace std;
int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    cin>>x>>y;
    int count = 0;
    int inc =1;
    while(true){
        if(y>=min(x+inc, x)&&y<=max(x+inc, x)){
            count+=abs(y-x);
            break;
        }
        count+=2*abs(inc);
        inc *=2; inc*=-1;
    }
    cout<<count;
}