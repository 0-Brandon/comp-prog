#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin>>n;
    map<int,int> x;

    for(int i=0; i<n; i++){
        int temp, temp1;
        cin>>temp1>>temp;
        x[temp]=temp1;
    }
    int ans = 0;
    while(x.size()!=0){
        ans = max(x.rbegin()->first+x.begin()->first, ans);
        int temp = min(x.rbegin()->second,x.begin()->second);
        x.rbegin()->second-=temp;
        x.begin()->second-=temp;
        if(x.rbegin()->second<=0){
            x.erase(--x.end());
        }
        if(!x.empty()&&x.begin()->second<=0){
            x.erase(x.begin());
        }
    }
    cout<<ans;
}