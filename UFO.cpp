/*
ID: bwang741
TASK: ride
LANG: C++14
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
     string comet, group;
     cin>>comet>>group;
     long long cometsum = 1, groupsum = 1;
     for(int i=0; i<comet.size(); i++){
        cometsum = cometsum * (comet[i] - 'A' +1);
       
     }
     for(int i=0; i<group.size(); i++){
         groupsum = groupsum * (group[i] - 'A' +1);
     }
     if(cometsum%47 == groupsum%47){
        cout<<"GO\n";
     }else{
        cout<<"STAY\n";
     }
     return 0;
}