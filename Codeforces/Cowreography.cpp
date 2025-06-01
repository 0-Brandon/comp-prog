#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    string a, b;
    cin>>a>>b;
    int ans = 0;
    deque<pair<int,int>> dq;
    for(int i=0; i<n; i++){
        while(!dq.empty()&&dq.front().first<i){
            ans+=abs(dq.front().second);//we have to shift all the ones stacked here
            dq.push_back({dq.front().first+k,dq.front().second});
            dq.pop_front();
        }
        //dif is 1 is 10, -1 if 01
        int dif = a[i]-b[i];
        if(dif==0)continue;
        //if its empty, or they are the same direction 
        if(dq.empty()||dif/abs(dif)==dq.front().second/abs(dq.front().second)){
            if(dq.empty()||dq.front().first!=i){ //in case we moved one into this position
                dq.push_front({i,0});
            }
            dq.front().second+=dif; //in case we moved something into it, we add the count of outstanding mismatches
        }
        else{
            dq.front().second += dif;
            if(dq.front().second==0)dq.pop_front();
        }
    }
    cout<<ans<<"\n";
}