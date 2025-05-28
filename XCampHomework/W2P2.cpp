#include <bits/stdc++.h>

using namespace std;

int ma = 0;

struct piece {
    int c; 
    int o; 
    int val; 
    string s;
};
bool cmp(piece& x, piece& y) {
    int dx = x.o - x.c;
    int dy = y.o - y.c;
    if((dx > 0) ^ (dy > 0)) {
        return dx > dy;
    }
    if(dx > 0) {
        if(x.c == y.c) return dx > dy;
        return x.c < y.c;
    }
    if(x.o == y.o) return dx > dy;
    return x.o > y.o;
}
vector<int> solve(vector<piece> pieces) {
    vector<int> res(ma+1,0);
    for(auto p : pieces) {
        if(p.o >= p.c) {
            for(int j = ma; j >= 0; j--) {
                if(p.c > j) continue;
                if(res[j] < j) continue;
                res[j-p.c+p.o] = max(res[j-p.c+p.o],res[j]+p.val);
            }
        }
        else {
            for(int j = 0; j <= ma; j++) {
                if(p.c > j) continue;
                if(res[j] < j) continue;
                res[j-p.c+p.o] = max(res[j-p.c+p.o],res[j]+p.val);
            }
        }
    }
    return res;
}
string rev(string s) {
    for(auto& i : s) {
        if(i == ')') {
            i = '(';
        }
        else {
            i = ')';
        }
    }
    reverse(s.begin(),s.end());
    return s;
}
int getcost(string s) {
    int cost = 0;
    int curr = 0;
    for(auto i : s) {
        if(i == ')') curr++;
        else curr--;
        cost = max(cost,curr);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;
    vector<string> input(n);
    for(auto& i : input) {
        cin >> i;
        ma += i.size();
    }
    vector<piece> pieces; 
    for(auto i : input) {
        piece p;
        p.s = i;
        p.c = getcost(i);
        p.o = getcost(rev(i));
        p.val = i.size();
        pieces.push_back(p);
    }
    sort(pieces.begin(),pieces.end(),cmp);
    vector<int> res = solve(pieces);
    cout << res[0] << endl;
}