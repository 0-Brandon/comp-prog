#include <bits/stdc++.h>
//doesn't account for if strings are contained in another string
using namespace std;
int HB = 31;

int overlap(string a, string b){
    int ha=0, hb = 0;
    int cnt = 0;
    int t = 1;
    int ap = a.size()-1, bp = 0;
    while(ha==hb&&ap>=0&&bp<b.size()){
        ha = HB*ha + a[ap];
        hb = hb+t*b[bp];
        ap--,bp++;
        t*=HB;
        if(ha==hb)cnt++;
    }
    return cnt;
}
int main(){
    vector<string> x(3);
    cin>>x[0]>>x[1]>>x[2];
    int tot = x[0].size()+x[1].size()+x[2].size();
    sort(x.begin(),x.end());
    int ans = 0;
    do{
        ans = min(ans,tot - (overlap(x[0],x[1]) + overlap(x[1],x[2])));
    }while(next_permutation(x.begin(),x.end()));
}