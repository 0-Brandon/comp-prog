#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    bool edge = true;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        edge&=(b[i]==0);
    }
    if(edge){
        for(auto& i:a)if(i>0){cout<<"No";return 0;}
        cout<<"Yes";return 0;
    }
    bool done = false;
    while(!done){
        done = true;
        for(int i=0; i<n; i++){
            if(a[i]<=b[i])continue;
            done = false;
            int amt = (a[i]-b[i]+1)/2;
            a[(i+1)%n]+=amt;
            a[i]-=2*amt;
        }
    }
    for(int i=0; i<n; i++){
        if(b[i]!=a[i]){cout<<"No";return 0;}
    }
    cout<<"Yes";
}