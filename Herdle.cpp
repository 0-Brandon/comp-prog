#include <bits/stdc++.h>
using namespace std;

int main(){

vector<char[3]> x(3);
vector<char[3]> y(3);

    int green=0;
    int yellow=0;
    for(int i=0;i<3;i++) cin>>x[i];
    for(int i=0;i<3;i++) cin>>y[i];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        if(x[i][j]==y[i][j]) {green++;
        x[i][j]='9';
        y[i][j]=')';
        }
    }
}

for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++) {
                for(int l=0;l<3;l++) {
                    if(x[i][j]==y[k][l]) {
                        y[k][l]=')';
                        x[i][j]='9';
                        yellow++;
                    }
                }
            }
        }
}

cout<<green<<"\n";
cout<<yellow;
return 0;
}