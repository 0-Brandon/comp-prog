
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 1;
    int t = 1;
    int m = 78;
        while(true){
        int te = t-m;
        if(te==0)break;
        n++;
        t+=n;
    }
    cout<<(n);
}