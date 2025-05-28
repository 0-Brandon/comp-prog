#include <bits/stdc++.h>

using namespace std;
double slope(double x1, double y1, double x2, double y2){
    if(x2-x1==0) return 0;
    return (y2-y1)/(x2-x1);
}
int area(int x1, int x2, int y2, int y3){
    return abs((x1-x2)*(y3-y2));
}
int main(){
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin>>n;
    vector<double> x(n);
    vector<double> y(n);
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i];
    }
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k =0; k<n; k++){
                if(slope(x[i], y[i], x[j], y[j])==0 && slope(x[k], y[k], x[j], y[j])==0){
                    ans = max(ans, area(x[i], x[j], y[j], y[k]));
                }
            }
        }
    }
    cout<<ans;

}