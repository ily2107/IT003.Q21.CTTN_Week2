while(q--){
        int a,b;
        cin >> a >> b;
        if (isFather(T,a,b)) cout << a << " la cha cua " << b << "\n";
        else if (isFather(T,b,a)) cout << b << " la cha cua " << a << "\n";
        else cout << a << " va " << b << " khong co quan he cha con\n";
    }
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
