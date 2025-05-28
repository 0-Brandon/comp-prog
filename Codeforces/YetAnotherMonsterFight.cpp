#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,i+x[i]);
    }
    vector<int> m(n+1);
    for(int i=n;i-->0;){
        m[i] = i+x[i];
        if(i<n-1)m[i]=max(m[i],m[i+1]);
    }
    m.back()=0;
    int lm = -1;
    for(int i=1; i<n; i++){
        int cl;
        int cur = x[i-1]+(n-i);
        lm = max(lm,cur);
        ans = min(ans,max({lm,m[i+1],x[i]}));
    }
    cout<<ans<<"\n";
}