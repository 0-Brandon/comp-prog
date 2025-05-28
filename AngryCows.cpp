#include <bits/stdc++.h>

using namespace std;
int n,k;
bool ok(long long mid, vector<int>& x){
    long long i=0;
    long long count=0;
    while(i<x.size()){
        count++;
        i=upper_bound(x.begin(),x.end(),x[i]+2*mid)-x.begin();
    }
    return count<=k;
}
int main(){
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    cin>>n>>k;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    long long  low=0, high=x[n-1];
    while(low<high){
        long long mid = low+(high-low)/2;
        if(ok(mid, x)){
            high=mid;
        }else{
            low=mid+1;
        }
    }
    cout<<low<<"\n";
}