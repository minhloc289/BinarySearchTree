#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left, * right;
};

typedef Node* Tree;

Tree getNode(int x) {
    Node* p = new Node;
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

void NLR(Tree& T) {
    if (T) {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

Tree rotateRight(Tree& T) {
    if (T == NULL) {
        cout << "\nKhong the xoay vi cay rong";
    }
    else if (T->left == NULL) {
        cout << "\nKhong the xoay phai vi khong co nut con ben trai";
    }
    else {
        Node* p = T->left;
        T->left = p->right;
        p->right = T;
        T = p;
    }
    return T;
}



int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "NLR: "; NLR(T);
	T = rotateRight(T);
	cout << "\nUpdated Tree: \n";
	cout << "NLR: "; NLR(T);
	return 0;
}




