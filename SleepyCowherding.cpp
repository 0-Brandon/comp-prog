#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);
    int ansmax, ansmin;
    int a, b, c;
    cin>>a>>b>>c;
    int d1 = abs(a-b),d2=abs(b-c);
    ansmax=max(d1,d2)-1;
    if(d1==2||d2==2){
        ansmin=1;
    }else{
        ansmin=2;
    }
    if(d1==1&&d2==1){
        ansmin=0;
        ansmax=0;
    }
    cout<<ansmin<<"\n"<<ansmax;
}