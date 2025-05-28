#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n=0;
    cin>>n;
    vector<int> e(n),b;
    for(int i=0; i<n; i++){
        cin>>e[i];
    }
    sort(e.begin(), e.end());
    int idx =0;
    for(int i=1; i<=2*n; i++){
        if(e[idx]==i){
            idx++;
        }else{
            b.push_back(i);
        }
    }
    sort(b.begin(), b.end());
    
    int idxe=0,idxb=0;
    int ans = 0;
    while(idxb<n){
        if(b[idxb]>e[idxe]){
            idxb++;
            idxe++;
            ans++;
        }
        else{
            idxb++;
        }
    }
    cout<<ans;
}