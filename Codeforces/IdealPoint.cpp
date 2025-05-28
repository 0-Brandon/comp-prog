#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> ans(51,0);
    vector<int> dif(52,0);
    for(int i=0; i<n; i++){
        int l ,r;
        cin>>l>>r;
        if(k>=l&&k<=r){
            dif[l]+=1;
            dif[r+1]-=1;
        }
    }
    int run = 0;
    int kth = 0;
    for(int i=0; i<51; i++){
        run+=dif[i];
        dif[i]=run;
        if(i==k){
            kth=dif[i];
        }
    }
    sort(dif.begin(),dif.end());
    if(kth>dif[dif.size()-2]){
        cout<<"yes";
    }
    else{
        cout<<"No";
    }
    cout<<"\n";


}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}