#include <bits/stdc++.h>

using namespace std;
int next(int i, int a1, int a2, int b1, int b2){
    if(i>=a1&&i<=a2){
        i=a2-i+a1;
    }
    if(i>=b1&&i<=b2){
        i=b2-i+b1;
    }
    return i;
}
int main(){
    freopen("swap.out","w",stdout);
    freopen("swap.in","r",stdin);
    int n,k;
    cin>>n>>k;
    int a1,a2, b1,b2;
    cin>>a1>>a2>>b1>>b2;
    vector<int> ans(n+1);
    for(int i=1; i<=n; i++){
        int j = next(i,a1,a2,b1,b2);
        int count = 1;
        while(j!=i){
            count++;
            j=next(j,a1,a2,b1,b2);
        }
        for(int l=0; l<k%count; l++){
             j=next(j,a1,a2,b1,b2);
        }
        ans[j]=i;
    }
    for(int i=1; i<n+1; i++){
        cout<<ans[i]<<"\n";
    }
}