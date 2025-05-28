#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    int l=0,r=n-1;
    int mul = 0;
    vector<bool> r(n,false);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    if(n%k!=0){cout<<"NO\n";return;}
    for(int i=0; i<k-1; i++){
        vector<int> cur;
        while(x[l]%k!=0)l++;
        while(x[r]%k!=0)r--;
        cur.push_back(l);
        int ll =l;
        int  rr= r;
        for(int a=0; a<k-2; a++){
            while
        }
        cur.push_back(r);
        
    }
}
int main(){
    int t;
    cin>>t;
    solve();
}