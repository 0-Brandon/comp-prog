#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    string x = "aeiou";
    while(t--){
        int n;cin>>n;
        for(int i=0; i<5; i++){
            cout<<string(n/5+(i<n%5),x[i]);
        }
        cout<<"\n";
    }
}