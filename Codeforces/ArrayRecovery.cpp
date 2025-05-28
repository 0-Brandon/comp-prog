#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        bool done = false;
        int n;
        cin>>n;
        vector<int> d(n);
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>d[i];
        }
        a[0]=d[0];
        for(int i=1; i<n; i++){
            if(a[i-1]-d[i]>=0&&d[i]!=0){
                cout<<-1<<"\n";
                done = true;
                break;
            }
            a[i]=a[i-1]+d[i];
        }
        if(!done){
            for(auto i:a){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
    }
}