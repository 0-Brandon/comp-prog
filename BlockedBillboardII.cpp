#include <bits/stdc++.h>

using namespace std;

int main(){

    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int ans = (x2-x1)*(y2-y1);
    int area = 0;
    int dx = min(x2, x4)-max(x1,x3);
    int dy = min(y2, y4)-max(y1, y3);
    area = dx*dy;
    if(area>0){
        if((x2==x4&&x1==x3)||(y2==y4&&y1==y3))
        ans-=area;
    }
    cout<<ans;
}