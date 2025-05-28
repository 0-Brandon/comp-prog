#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        x[i]-=1;
    }
    string s = "";
    int i=0;
    while(i<n){
        if(x[i]==1){
            s.append(1,'R');
            i++;
        }else{
            int j=i;
            int pol = x[i];
            while(x[++j]>=pol&&j<n){
                x[j]-=(x[i]/2)*2;
            }
            int a = x[i]/2;
            x[i]=1;
            while((a--)){
                s.append(j-i,'R');
                s.append(j-i,'L');
            }
        }
    }
    s.append(n,'L');
    cout<<s;
}