#include <bits/stdc++.h>
using namespace std;
string s;
bool win=false;
int main(){
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(win) break;
        if(s[i]=='A'&&s[i+1]=='B'){
            for(int j=0;j<i-1;j++){
                if(s[j]=='B'&&s[j+1]=='A'){
                    win=true;
                }
            }
        }
    }
    if(!win){
     for(int i=0;i<s.length();i++){
         if(win) break;
        if(s[i]=='B'&&s[i+1]=='A'){
            for(int j=0;j<i-1;j++){
                if(s[j]=='A'&&s[j+1]=='B'){
                    win=true;
                }
            }
    
        }
    }
}

    if(!win){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
}