#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c, n;
    cin>>c>>n;
    vector<pair<int,int>> cows(n);
    vector<int> chickens(c); //END TIME, START TIME!!!!!
    for(int i=0; i<c; i++){
        cin>>chickens[i];
    }
    for(int i=0; i<n; i++){
        cin>>cows[i].second>>cows[i].first;
    }
    sort(cows.begin(),cows.end());
    sort(chickens.begin(),chickens.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        auto j = lower_bound(chickens.begin(),chickens.end(), cows[i].second);
        if(j!=chickens.end()&&*j<=cows[i].first){
            chickens.erase(j);
            ans++;
        }
        if(!chickens.size())break;
    }
    cout<<ans;
}