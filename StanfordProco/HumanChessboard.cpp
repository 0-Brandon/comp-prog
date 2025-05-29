#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n;
    cin>>n;
    int cx,cy;
    cin>>cx>>cy;
    int bx,by,rx,ry;cin>>rx>>ry>>bx>>by;
    if((rx==cx&&bx==cx&&((ry>by&&by>cy)||(ry<by&&by<cy)))||(ry==cy&&by==cy&&((rx>bx&&bx>cx)||(rx<bx&&bx<cx))))cout<<"2\n";
    else if(rx==cx||ry==cy)cout<<"1\n";
    else if(abs(by-cy)==abs(bx-cx))cout<<"1\n";
    else cout<<"2\n";
}