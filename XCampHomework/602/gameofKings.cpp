/*
this python code works because precision is just messed up bruh
import sys

n = int(input().strip())
a = [0] * (n + 1)
b = [0] * (n + 1)
a[0], b[0] = map(int, input().split())
for i in range(1, n + 1):
    a[i], b[i] = map(int, input().split())
eps = 1e-7
for i in range(n - 1):
    for j in range(1, n - i):
        if a[j] / b[j + 1] > a[j + 1] / b[j]:
            a[j], a[j + 1] = a[j + 1], a[j]
            b[j], b[j + 1] = b[j + 1], b[j]
        if abs(a[j] / b[j + 1] - a[j + 1] / b[j]) < eps and b[j] > b[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            b[j], b[j + 1] = b[j + 1], b[j]
cur = 1
ans = 0
for i in range(n + 1):
    ans = max(ans, cur // b[i])
    cur *= a[i]
print(ans)
*/



#include <bits/stdc++.h>
#define int long long
using namespace std;
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
signed main(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    cin>>a[0]>>b[0];
    for(int i=1; i<=n; i++){
        cin>>a[i]>>b[i];
    }
    //the next one is cur*a[i]/b[i+1]
    double eps = 1e-7;
    for(int i=0; i<n-1; i++){
        for(int j=1; j<n-i; j++){
            if(a[j]*1.0/b[j+1]>a[j+1]*1.0/b[j])swap(a[j],a[j+1]),swap(b[j],b[j+1]);
            if(abs(a[j]*1.0/b[j+1]-a[j+1]*1.0/b[j])<eps&&b[j]>b[j+1])swap(a[j],a[j+1]),swap(b[j],b[j+1]);
        }
    }
    __int128_t cur = 1;
    __int128_t ans = 0;
    for(int i=0; i<=n; i++)ans = max(ans,cur/b[i]),cur*=a[i];
    print(ans);
}
