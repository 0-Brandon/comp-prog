#include <bits/stdc++.h>

using namespace std;

int main(){
    int m,t,u,f,d;
    cin>>m>>t>>u>>f>>d;
    vector<int> reg(t);
    vector<int> back(t);
    for(int i=0; i<t; i++){
        char temp;
        cin>>temp;
        if(temp=='u'){
            reg[i]=u;
            back[i]=d;
        }
        if(temp=='d'){
            reg[i]=d;
            back[i]=u;
        }
        else{
            reg[i]=f;
            back[i]=f;
        }
    }
    int costr=0,costb=0;
    int i=0;
    for(;i<t; i++){
        costr+=reg[i];
        costb+=back[i];
        if(costb+costr>m){
            break;
        }
    }
    cout<<i;
}