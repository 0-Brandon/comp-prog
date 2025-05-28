#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n;
    cin>>n;
    vector<bool> el(2*n+1,false);
    vector<int> e, e1, e2, b, b1, b2;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        el[t]=true;
        e.push_back(t);
    }
    for(int i=1; i<=2*n; i++){
        if(!el[i])
        b.push_back(i);
    }



    for(int i=0; i<n; i++){
        if(i<n/2)e1.push_back(e[i]);
        else e2.push_back(e[i]);
    }
    sort(b.begin(), b.end(), greater<int>());
    for(int i=0; i<n; i++){
        if(i<n/2)b1.push_back(b[i]);
        else b2.push_back(b[i]);
    }



    sort(e1.begin(),e1.end(), greater<int>());
    sort(e2.begin(),e2.end());
    sort(b2.begin(),b2.end());

    int ans = 0;
    int bi = 0;
    int idx = n/2-1;
    for(int i=0; i<n/2; i++){
        if(b1[bi]>e1[i]){
            ans++;
            bi++;
        }else{
            b1[idx--]=0;
        }
    }
    bi=0, idx=n/2-1;
    for(int i=0; i<n/2; i++){
        if(b2[bi]<e2[i]){
            ans++;
            bi++;
        }else{
            b2[idx--]= INT_MAX;
        }
    }
    cout<<ans;
}