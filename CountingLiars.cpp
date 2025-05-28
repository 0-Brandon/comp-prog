#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,count;
    int mini=100000001,maxi=-1;
    
    cin>>x;
    int num[x];
    char letter[x];
    for(int i=0;i<x;i++){
        cin>>letter[i]>>num[i];
        
    }
    
    for(int i=0;i<x;i++){
        if(letter[i]=='L'){
            if(num[i]<maxi){
                maxi=num[i];
            }
        } else {
            if(num[i]>mini){
                mini=num[i];
            }

        }
    }
    
    for(int i=0;i<x;i++){
        if(letter[i]=='L'){
            if(num[i]<mini){
                count++;
            }
        } else {
            if(num[i]>maxi){
                count++;
            }

        }
    }
cout<<count;
}