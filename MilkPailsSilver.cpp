#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("pails.in","r",stdin);
    freopen("pails.out","w",stdout);
    int a, b, k, m;
    cin>>a>>b>>k>>m;
    vector<int> x(1000, INT_MAX-1);
    x[a]=1;
    x[b]=1;
    x[0]=0;
    for(int i=0; i<1000; i++){
        if(i>=a)x[i]=min(x[i-a]+1,x[i]);
        if(i>=b)x[i]=min(x[i-b]+1,x[i]);
    }
    for(int i=0; i<1000; i++){
        x[i]=min(x[i+a]+1,x[i]);
        x[i]=min(x[i+b]+1,x[i]);
    }
    int ans = INT_MAX;
    for(int i=0; i<1000; i++){
        if(x[i]<k){
            ans = min(ans, abs(m-i));
        }
    }
    cout<<ans;
}