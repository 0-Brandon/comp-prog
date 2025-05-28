#include <bits/stdc++.h>

using namespace std;
void solve(){
    vector<int> x(10);
    for(int i=0; i<10;i++)cin>>x[i];
    int idx=0, m=INT_MAX;
    for(int i=9; i>=1; i--){
        if(x[i]<m){
            m=x[i];
            idx=i;
        }
        if(x[i]==m){
            idx=min(idx,i);
        }
    }
    if(x[0]<m){
        m=x[0];
        idx=0;
        for(int i=1; i<10; i++){
            if(x[i]==0){
                cout<<i<<"\n";
                return;
            }
        }
        cout<<"1"+string(m+1,'0')<<"\n";
    }else{
        if(m==0){
            cout<<idx<<"\n";
            return;
        }
        cout<<string(m+1,idx+'0')<<"\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}