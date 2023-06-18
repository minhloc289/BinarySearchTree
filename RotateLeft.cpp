#include <iostream>
using namespace std;

typedef struct node {
    int info;
    node* right, * left;
};

typedef node* Tree;

Tree getNode(const int x) {
    node* p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InsertTree(Tree& T, const int &x) {
    if (T != NULL) {
        if (x < T->info) {
            InsertTree(T->left, x);
        }
        else if (x > T->info) {
            InsertTree(T->right, x);
        }
    }
    else T = getNode(x);
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        InsertTree(T, x);
    }
}

void NLR(Tree& T) {
    if (T) {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

void RotateLeft(Tree& T) {
    if (T->right == NULL) {
        cout << "\nKhong the xoay trai vi khong co nut con ben phai";
        return;
    }
    node* p = T->right;
    T->right = p->left;
    p->left = T;
    T = p;        
}
    

int main() {
    Tree T = NULL;
    inputTree(T);
    cout << "NLR: "; NLR(T);
    if (T == NULL) {
        cout << "\nKhong the xoay vi cay rong";
    }
    else {
        RotateLeft(T);
        cout << endl;
        cout << "NLR: "; NLR(T);
    }
    
 
}

