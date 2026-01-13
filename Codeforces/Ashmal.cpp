#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        string st;
        cin>>st;
        if(s+st<st+s)s+=st;
        else s=st+s;
    }
}
int main(){
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}