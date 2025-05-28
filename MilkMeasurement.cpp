#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("measurement.in","r",stdin);
    freopen("measurement.out","w",stdout);
    int n, g;
    cin>>n>>g;
    vector<tuple<int,int,int>> x;
    map<int,int> milknums;
    map<int,int> acc;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        x.emplace_back(a, b, c);
        acc[b]=g;
        milknums[g]++;
    }
    sort(x.begin(),x.end());
    int count = 0;
    for(auto&[day, cow, change]: x){
        int prev = acc[cow];
        int pcount = milknums[prev];
        bool wasup = prev == milknums.rbegin()->first;
        milknums[prev]--;
        if(milknums[prev]==0) milknums.erase(prev);
        prev+=change;
        acc[cow]+=change;
        milknums[prev]++;
        int ncount = milknums[prev];
        bool isup = prev == milknums.rbegin()->first;
        if(wasup){
            if(isup&&ncount == pcount) continue;
            else count++;
        }
        else{
            if(isup) count++;
        }
    }
    cout<<count<<"\n";
}