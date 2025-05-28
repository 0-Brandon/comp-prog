#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int amax = 0;
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    amax = max(x[n-2]-x[0], x[n-1]-x[1]);
    amax-=(n-2);
    int mcows = 0;
    int i=0, j=0;
    if((x[n-1]-x[1]==n-2&&x[1]-x[0]>2)||(x[n-2]-x[0]==n-2&&x[n-1]-x[n-2]>2))mcows=n-2; 
    else while(i<n){
        while(j<n-1&&x[j+1]-x[i]+1<=n)j++;
        mcows=max(mcows,j-i+1);
        i++;
    }
    cout<<(n-mcows)<<"\n"<<amax;
}