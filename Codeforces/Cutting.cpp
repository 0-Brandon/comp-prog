#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,b;
    cin>>n>>b;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int e=0,o=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<n-1; i++){
        if(x[i]%2==0)e++;
        else o++;
        if(e==o)pq.push(abs(x[i]-x[i+1]));
    }
    int ans = 0, cur=0;
    while(!pq.empty()){
        if(cur+pq.top()>b)break;
        ans++;
        cur+=pq.top();
        pq.pop();
    }
    cout<<ans<<"\n";
}