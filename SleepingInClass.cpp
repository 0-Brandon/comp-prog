#include <bits/stdc++.h>

using namespace std;
int T;
priority_queue<int> x,x1;
int p;
int main(){
cin>>T;


for(int i=0;i<T;i++){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>p;
        x.push(p);
    }
    x1.push(*x.begin()+*x.begin()+1);
    for(int i=1;i<N;i++){
        x1.push()
    }

}

}