#include <bits/stdc++.h>

using namespace std;
bool check(int x, int y){
    while(x>=0 && y>=0){
        if(x==0 || y==0){
            return true;
        }
        if(x%10+y%10>=10){
            return false;
        }
        x/=10;
        y/=10;
    }
    return false;
}
int main(){

    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];   
    }
    int sum = 0, ans = 0, count = 0;
    for(int i=0; i<pow(2,n); i++){
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                if(check(sum, x[j])){
                    sum+=x[j];
                    count++;
                }
            }
        }
        if(sum>ans){
            ans = count;
        }
        count = 0;
        sum=0;
    }
    cout<<ans;
}