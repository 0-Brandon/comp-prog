#include <bits/stdc++.h>
//I can change this to work but its a testament to how far I've come
using namespace std;
int cv(int pos, string s, int base,int inc){
    s[pos]=s[pos]+inc%base;
    int num=0;
    int j=0;
    for(int i=s.size()-1; i>=0; i--){
        num+=pow(base,j++)*s[i];
    }
    return num;
}
int main(){
    string b2,b3;
    cin>>b2>>b3;
    for(int i=0; i<b2.size(); i++){
        for(int j=0; j<b3.size(); j++){
            int x = cv(i,b2,2,1);
            int y = cv(j,b3,3,1);
            int l = cv(j,b3,3,-1);
            int k=cv(i,b2,2,-1);
            if(x==y||x==l){
                cout<<x;
                break;
            }if(l==y||l==k){
                cout<<l;
                break;
            }
        }
    }
}