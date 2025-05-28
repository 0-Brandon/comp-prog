#include <bits/stdc++.h>

using namespace std;
int n, m, c;
bool test(int t,vector<int>& x){
    int mcur=m;
    int count = 0;
    int lastidx=0;
    for(int i=0; i<n; i++){
        if(x[i]-x[lastidx]>t||count==c){
            count = 0;
            mcur--;
            lastidx=i;
        }
        count++;
        if(mcur==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("convention.out","w",stdout);
    freopen("convention.in","r",stdin);
    cin>>n>>m>>c;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int high = *x.rbegin()-x[0],low = 0;
    while(low<high){
        int mid = low+(high-low)/2;
        if(test(mid,x)){
            high = mid;
        }else{
            low = mid+1;
        }
    } 
    cout<<low;
}