#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            double sum = 0.0;
            for(int k=i; k<=j; k++){
                sum+=x[k];
            }
            sum/=(j-i+1);
            for(int k=i; k<=j; k++){
                if(x[k]==sum){
                    count++; 
                    break;
                }
            }
        }
    }
    cout<<count;
}