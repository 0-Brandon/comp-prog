#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;
    vector<int> x(7);
    for(int i=0; i<7; i++){
        cin>>x[i];
    }
    sort(x.begin(), x.end());
    a=x[0];
    b=x[1];
    c=x[6]-a-b;
    cout<<a<<" "<<b<<" "<<c;
}