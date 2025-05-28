#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        bool f = true;
        for(int i=0; i<n; i++){
            if(i*(i-1)/2+(n-i-1)*(n-i)/2==k){
                f=false;
                cout<<"YES\n";
                for(int j=0; j<n; j++){
                    if(j<i)cout<<1;
                    else cout<<-1;
                    cout<<" ";
                }
                cout<<"\n";
                break;
            }
        }
        if(f)cout<<"NO\n";
    }
}