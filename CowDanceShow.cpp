#include <bits/stdc++.h>

using namespace std;
vector<int> x;
int t;
bool ok(int k){
    priority_queue<int> pq;
    for(int i=0; i<k; i++){
        pq.push(-x[i]);
    }
    int idx = k;
    int last = 0;
    while(!pq.empty()){
        int cur = pq.top();
        last = cur;
        pq.pop();
        if(idx<x.size())pq.push(cur-x[idx++]);
    }
    return -last<=t;
}
int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    int n;
    cin>>n>>t;
    x.resize(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int low = 0, high = n;
    while(low<high){
        int k = low+(high-low)/2;
        if(ok(k)){
            high = k;
        }else{
            low=k+1;
        }
    }
    cout<<low;
}