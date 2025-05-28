#include <bits/stdc++.h>

using namespace std;
int main(){
    int b,e;
    cin>>b>>e;
    int first = 1;
    vector<int> x(2000010);
    int bes = 1000000, els=1000000;
    vector<int> bessie(b),elsie(e);
    for(int i=0; i<b; i++){
        char temp;
        cin>>bessie[i]>>temp;
        if(temp=='L')bessie[i]*=-1;
    }
    for(int i=0; i<e; i++){
        char temp;
        cin>>elsie[i]>>temp;
        if(temp=='L')elsie[i]*=-1;
    }
    int count = 0;
    int idxb=0,idxe=0;
    if(bes+b[idxb]>=e+els[idxe])first=1;
    else first=-1;
    while(true){
        if(idxb!=b-1)bes+=b[idxb++];
        if(idxe!=e-1)els+=e[idxe++];
        if((first==1&&els>=bes)||(first==-1&&bes>=els)){
            first*=-1;
            count++;
        }
        if(idxe==e-1&&idxb==b-1){
            break;
        }
    }
cout<<count;
}