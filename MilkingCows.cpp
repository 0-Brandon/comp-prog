/*
NAME: bwang741
LANG:C++17
TASK:milk2
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
    int n;
    cin>>n;
    map<int,int> x;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x[a]++;
        x[b]--;
    }
    int ans=0, ans1=0;
    int counton=0;
    int startx=-1, starty=-1;
    for(auto[l,y]:x){
        if(y>=0){
            counton+=y;
            if(starty>=0){
            ans1 = max(l-starty, ans1);
            starty=-1;
            }
            if(startx<0) startx = l;
        }
        if(y<0){
            counton+=y;
            if(counton==0){
            ans = max(l-startx, ans);
            startx=-1;
            starty=l;
            }
        }
    }
    cout<<ans<<" "<<ans1<<"\n";
}