#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
    int n;cin>>n;
    vector<int> x(2*n);
    int a = 0;
    int cnt = 0;
    for(int i=0; i<2*n; i++){
        cin>>x[i];
        a^=x[i];
        cnt+=x[i];
    }
    if(cnt>n)cnt = n-(cnt-n);
    cout<<a<<" "<<cnt<<"\n";
    }
}