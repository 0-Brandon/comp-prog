#include <bits/stdc++.h>

using namespace std;

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n = 200, m = 200;
    uniform_int_distribution<int>  d(0,255),d1(1,n), d2(1,2),d4(0,7);
    cout<<n<<" "<<m<<" "<<"\n";
    int cnt =  0;
    int l = 0;
    for(int i=0; i<n; i++)cout<<(l=d(rng))<<" ";cout<<"\n";
    for(int i=0; i<m; i++){
        int a = d2(rng);
        if(a==1){
            cnt++;
            cout<<a<<" "<<(l = l^(1<<d4(rng)))<<" ";cout<<"\n";
        }else{
            uniform_int_distribution<int>  d3(0,cnt);
            cout<<a<<" "<<n+d3(rng);cout<<"\n";
        }
    }
}