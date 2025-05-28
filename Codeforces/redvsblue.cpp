#include <bits/stdc++.h>
using namespace std;
int main(){
    int N; cin>>N;
    while(N--){
        int n, b, r;
        cin>>n>>r>>b;
        int num = r/(b+1);
        vector<char> x;
        int countr = 0, countb = 0;
        while(countr < r){
            for(int i=0; i<num; i++){
                if(countr<r)x.push_back('R');
                countr++;
            }
            if(countb < b){
                x.push_back('B');
                countb++;
            }
        }
        for(int i=0; i<x.size(); i++){
            cout<<x[i];
        }
        cout<<"\n";
    }
}