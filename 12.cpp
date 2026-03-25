//Created by Vũ Thị Thu Hường
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define ily2107 "ily2107"
#define time (1.0*clock()/CLOCKS_PER_SEC)
struct TNode{
    int key;
    TNode* pLeft;
    TNode* pRight;
};

struct Tree{
    TNode* root;
};

void CreateTree(Tree &T) {T.root = NULL;}
TNode* CreateTNode(int x) {
    TNode* p;
    p = new TNode;
    if (p==NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
void Insert(Tree &T, int x) {
    TNode* p=CreateTNode(x);
    if (T.root==NULL) {
        T.root=p;
        return;
    }
    TNode* cur=T.root;
    TNode* parent=NULL;
    while (cur!=NULL) {
        parent=cur;
        if (x<cur->key) cur=cur->pLeft;
        else if (x>cur->key) cur=cur->pRight;
        else {
            delete p;
            return;
        }
    }
    if (x<parent->key) parent->pLeft=p;
    else parent->pRight=p;
}
bool isFather(Tree T, int parent, int child){
    TNode* cur=T.root;
    while (cur){
        if(cur->key==parent)
            return (cur->pLeft && cur->pLeft->key == child) || (cur->pRight && cur->pRight->key == child);
        else if(parent<cur->key) cur=cur->pLeft;
        else cur=cur->pRight;
    }
    return false;
}
void run(int q, Tree T){
    while(q--){
        int a,b;
        cin >> a >> b;
        if (isFather(T,a,b)) cout << a << " la cha cua " << b << "\n";
        else if (isFather(T,b,a)) cout << b << " la cha cua " << a << "\n";
        else cout << a << " va " << b << " khong co quan he cha con\n";
    }
}
signed main() {
    freopen(ily2107".inp","r",stdin);
    freopen(ily2107".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    Tree T;
    CreateTree(T);
    int n; cin >> n;
    int data;
    while(n != 0) {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q; cin >> q;
    run(q, T);
    
    return 0;
}
