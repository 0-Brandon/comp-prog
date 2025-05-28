#include <bits/stdc++.h>

using namespace std;
//First Platinum BABY!!!!!!!
//4/7/2023
//same code as gold lmfao
int main() {
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> x(n);
    for (int i=0; i<n; i++) {
        cin>>x[i];
    }
    stack<int> s;
    int ans = 0;
    for (int i=0; i<n;i++) {
        int cur=x[i];
        while (!s.empty()&&s.top()==cur) {
            s.pop();
            cur++;
        }
        s.push(cur);
        ans=max(ans, cur);
    }
    while(!s.empty()) s.pop();
    for (int i=n-1; i>=0; i--) {
        int cur=x[i];
        while (!s.empty()&&s.top()==cur) {
            s.pop();
            cur++;
        }
        s.push(cur);
        ans=max(ans, cur);
    }
    cout<<ans;
}

