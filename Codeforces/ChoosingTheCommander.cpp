#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node* left,* right;
    int num;
    Node():left(0),right(0),num(0){};
}* root;
void insert(int a){
    Node* cur = root;
    for(int i=27; i>=0; i--){
        cur->num++;
        if(a&(1<<i)){
            if(!cur->right)cur->right = new Node();
            cur = cur->right;
        }
        else{
            if(!cur->left)cur->left = new Node();
            cur = cur->left;
        }
    }
    cur->num++;
}
void del(int a){
    Node* cur = root;
    for(int i=27; i>=0; i--){
        cur->num--;
        if(a&(1<<i)){
            cur = cur->right;
        }
        else{
            cur = cur->left;
        }
    }
    cur->num--;
}
int query(int a,int l){
    Node* cur = root;
    int ans = 0;
    a=a^l;
    for(int i=27; i>=0&&cur; i--){
        if(a&(1<<i)){
            if(cur->left)ans+=cur->left->num * !!(l&(1<<i));
            cur = cur->right;
        }
        else{
            if(cur->right)ans+=cur->right->num * !!(l&(1<<i));
            cur = cur->left;
        }
    }
    return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    root = new Node();
    int q;
    cin>>q;
    while(q--){
        int t,a;
        cin>>t>>a;
        if(t==1){
            insert(a);
        }else if (t==2){
            del(a);
        }else{
            int l;cin>>l;
            cout<<query(a,l)<<"\n";
        }
    }
}