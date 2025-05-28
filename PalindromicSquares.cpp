/*
NAME: bwang741
LANG: C++17
TASK: palsquare
*/


#include <bits/stdc++.h>

using namespace std;
void base(int x, int b){
    int a=x*x, q = 1, r=1;
    string ans = "";
    while(q!=0){
        q=a/b;
        r=a%b;
        a=q;
        if(r<10)
        ans.insert(0,to_string(r));
        else{
            ans.insert(0,1,(char)('A'+(r-10)));
        }
    }
    string temp = ans;
    reverse(ans.begin(), ans.end());
    if(temp == ans){
    a=x, q = 1, r=1;
    string baseog = "";
    while(q!=0){
        q=a/b;
        r=a%b;
        a=q;
        if(r<10)
        baseog.insert(0,to_string(r));
        else{
            baseog.insert(0,1,(char)('A'+(r-10)));
        }
    
    }
  cout<<baseog<<" "<<ans<<"\n";
    }
}

int main(){
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
    int b;
    cin>>b;
    for(int i=1; i<=300; i++){
        base(i,b);
    }
}