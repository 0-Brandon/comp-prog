#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    x.push_back(-1);
    stack<int> s;
    s.push(-1);
    int ans = 0;
    for(int i=0; i<=n; i++){
        while(s.top()!=-1&&x[s.top()]>=x[i]){
            int h = s.top();
            s.pop();
            ans =max(ans,x[h]*(i-1-s.top()));
        }
        s.push(i);
    }
    cout<<ans<<"\n";
}