#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){

}

//dp[i] is best answer if i is a fixed point
//when we are transitioning
//dp[a[i]]= ans - cost of removing this one
//we can add our edge if no one has added an edge to us
//so in our state we somehow need to encode which nodes have their edges extended
