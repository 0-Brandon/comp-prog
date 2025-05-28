#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> x;
bool ok(int time){
    int i=0, j=n-1;
    while(i<n&&x[i]-x[0]<=2*time)i++;
    while(j>=0&&x.back()-x[j]<=2*time)j--;
    if(i<j&&(x[j]-x[i]>2*time))return false;
    return true;
}
void solve(){
    cin>>n;
    x.resize(n);
    for(int i=0; i<n;  i++){
        cin>>x[i];
    }
    sort(x.begin(),x.end());
    int l=0, h=1e9;
    while(l<h){
        int m=l+(h-l)/2;
        if(ok(m)){
            h=m;
        }
        else{
            l=m+1;
        }
    }
    cout<<l<<"\n";
}
int main(){
    int t;
    cin.tie(0)->sync_with_stdio(false);
    cin>>t;
    while(t--){
        solve();
    }
}