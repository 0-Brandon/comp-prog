#include <bits/stdc++.h>

using namespace std;

int n, c, m;
bool ok(long long int total, vector<vector<long long int>>& friends){
    //we have total moonies to spend on satisfying the friends;
    //a+b=total;
    //for each friend, a*cookies+b*muffins <=wait
    // x is upgrade for cookies
    long long int lowx=max(1LL*1,c-total), highx = min(c+m-total-1,1LL*c);
    for(auto& i:friends){
        long long int ai=i[0], bi=i[1],ci=i[2];
        int d = (c+m-total);
        if(ai-bi>0){
            highx = min(highx,(ci-(d*bi))/(ai-bi));
        }
        else if(ai-bi<0){
            lowx = max(lowx,(ci-d*bi+ai-bi+1)/(ai-bi));
        }else{
            if(d*bi>ci)return false;
        }
    }
    return lowx<=highx;
}
void solve(){
    cin>>n>>c>>m;
    vector<vector<long long int>> friends;
    for(int i=0; i<n; i++){
        long long int a, b ,c;
        cin>>a>>b>>c;
        friends.push_back({a,b,c});
    }
    long long int low = 0, high = c+m;
    while(low<high){
        long long int mid = low+(high-low)/2;
        if(ok(mid,friends)){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    cout<<low<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}