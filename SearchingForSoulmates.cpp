#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a, b;
        int count = 0;
        cin>>a>>b;
        //if a>b: divide by 2 until a<b, then add 1
        //if a<b: recurse on b, divide b/2 as much as possible until b/2<a, and then count the number of steps needed to make a==b
        if(a>b){
            while(a>b){
                count++;
                if(a&1){
                    a++;
                    count++;
                }
                a>>=1;
            }
            count+=b-a;
        }
        else{
            while(b>>1>a){
                if(b&1){
                    b--;
                    count++;
                }
                b>>=1;
                count++;
            }
            count+=b-a;
        }
        cout<<count<<"\n";
    }
}