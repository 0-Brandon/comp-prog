/*
NAME: Brandon Wang
LANG: C++14
TASK: friday
*/
#include <bits/stdc++.h>

using namespace std;
bool leap(int year){
    if(year%4!=0) return false;
    if(year%100==0){
        if(year%400==0) return true;
        return false;
    }
    return true;
}
int main(){
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    int n;
    cin>>n;
    map<int, int> days;
    vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dow = 0;
    for(int i=0; i<12*n; i++){
        if(i%12==0){
            if(leap(1900+i/12)){
                months[1]=29;
            }
            else{
                months[1]=28;
            }
        }
        days[dow]++;
        dow+=months[i%12];
        dow%=7;
    }
    for(auto i:days){
        cout<<i.second;
        if(i.first!=6)cout<<" ";
        else cout<<"\n";
    }
}