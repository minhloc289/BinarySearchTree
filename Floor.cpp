#include<iostream>
using namespace std;

typedef struct node {
    int info;
    node* right, * left;
};

typedef node* Tree;

Tree getNode(int x) {
    node* p = new node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void InsertTree(Tree& T, int x) {
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

int floorBST(node* T, int x) {
    int floorVal = 201; 
    while (T != NULL) {
        if (T->info == x) {
            floorVal = x;
            break;
        }
        else if (T->info > x) { 
            T = T->left; 
        }
        else { 
            floorVal = T->info; 
            T = T->right; 
        }
    }
    return floorVal;
}

int main() {
    Tree T = NULL;
    inputTree(T);
    int x;
    cin >> x;
    int floorVal = floorBST(T, x);
    if (floorVal == 201) {
        cout << "201";
    }
    else {
        cout << floorVal  << endl;
    }
    return 0;
}

