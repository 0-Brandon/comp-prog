#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int n;
    cin>>n;
    vector<int> h(n),p(n),s(n);
    for(int i=0; i<n; i++){
        char t;
        cin>>t;
        if(i==0){
            h[i]=0;
            p[i]=0;
            s[i]=0;
            if(t=='H')h[i]=1;
            if(t=='P')p[i]=1;
            if(t=='S')s[i]=1;
            continue;
        }
        h[i]=h[i-1];
        p[i]=p[i-1];
        s[i]=s[i-1];
        if(t=='H'){
            h[i]++;
        }
        if(t=='P'){
            p[i]++;
        }
        if(t=='S'){
            s[i]++;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        int currmax = max({s[i],h[i],p[i]})+max({s[n-1]-s[i],h[n-1]-h[i],p[n-1]-p[i]});
        ans = max(currmax,ans);
    }
    cout<<ans;
}