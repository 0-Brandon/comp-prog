#include <bits/stdc++.h>

using namespace std;


int main(){
    int c, n;
    cin>>c>>n;
    if(c!=10){
    vector<int> x(n);
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<c; j++){
            x[i]|=((s[j]=='H')?1:0)<<j;
        }
    }

    for(int i=0; i<n; i++){
        int ans = 0;
        for(int j=0; j<n; j++){
            ans = max(ans,__builtin_popcount(x[i]^x[j]));
        }
        cout<<ans<<"\n";
    }
    }else{
        for(int i=0; i<n; i++)cout<<"0\n";
    }
}

