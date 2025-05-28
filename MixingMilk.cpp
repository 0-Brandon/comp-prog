#include <bits/stdc++.h>

using namespace std;
int x;
array<int, 3> A;
array<int, 3> C;

int mix(int a, int b, int c){
    return min(a, c-b);
}
int amt,current;
int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout); 
    for(int i=0;i<3;i++){
        cin>>A[i]>>C[i];
    }
    for(int i=0; i<100; i++){
        int temp = mix(C[i%3], C[(i+1)%3], A[(i+1)%3]);
        C[i%3] -= temp;
        C[(i+1)%3] += temp; 
    }
for(int i=0;i<3;i++){
cout<<C[i]<<"\n";
}
}