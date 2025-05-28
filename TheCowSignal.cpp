#include <bits/stdc++.h>

using namespace std;
int main(){
   int M, N, K;
   freopen("cowsignal.in", "r",stdin );
   freopen("cowsignal.out", "w", stdout);
   cin>>M>>N>>K;
   for(int i=0; i<M; i++){
    string temp;
    cin>>temp;
    for(int i=0; i<K; i++){
    for(auto i:temp){
        cout<<string(K,i);
    }
    cout<<"\n";
    }
   }
}