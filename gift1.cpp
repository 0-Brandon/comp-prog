/*
ID: bwang741
TASK: gift1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int NP;
    cin>>NP;
    map<string, int> x;
    map<int, string>order;
    int count = 0;
    for(int i=0; i<NP; i++){
        string temp;
        cin>>temp;
        x[temp] = 0;
        order[count++] = temp;
    }
    for(int i=0; i<NP; i++){
    string host;
    cin>>host;
    int amt, peop; 
    cin>>amt>>peop;
    if(peop != 0){
         int split = amt / peop; 
        for(int i=0; i<peop; i++){
            string rec;
            cin>>rec;
            x[rec] += split;
            x[host]-= split;
            amt -= split;
        }
    }
    }
    for(auto i: order){
        cout<<i.second<<" "<<x[i.second]<<"\n";
    }
    return 0;
}