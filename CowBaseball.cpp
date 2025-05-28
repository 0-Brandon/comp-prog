#include <bits/stdc++.h>

using namespace std;

int search(vector<int> x, int a){
    int n = x.size();
    int low = 0, high = n, mid = n/2;
    while(low<high){
        if(x[mid] < a){
            low = mid+1;
        }
        if(x[mid] >= a){
            high = mid;
        }
        mid = low+(high-low)/2;
    } 
    return low;
}
int main(){
    freopen("baseball.in", "r", stdin);
    freopen("baseball.out", "w", stdout);
    int n;
    int ans= 0;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.begin(), x.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int diff = x[j]-x[i];
            ans+=(search(x, x[j]+2*diff+1)-search(x, x[j]+diff));
        }
    }
    cout<<ans;
}