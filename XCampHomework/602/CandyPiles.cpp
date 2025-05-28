#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    sort(x.rbegin(),x.rend());
    int h = 0;
    int i;
    for(i=0; i<n; i++){
        if(i+1<n&&h+1<x[i+1])h++;
        else break;
    }
    int j=i;
    while(j+1<n&&x[j+1]==h+1)j++;
    if((x[i]-h-1)%2==0&&(j-i)%2==0)cout<<"Second\n";
    else cout<<"First\n";   
}