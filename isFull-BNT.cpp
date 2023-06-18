
#include <iostream>
using namespace std;

struct node {
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

void LNR(Tree T) {
    if (T) {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

int isFullBinaryTree(Tree T) {
    if (T == NULL) {
        return 1;
    }
    if (T->left == NULL && T->right == NULL) {
        return 1;
    }
    if (T->left != NULL && T->right != NULL){
        int left = isFullBinaryTree(T->left);
        int right = isFullBinaryTree(T->right);
        if (left && right) {
            return 1;
        }
    }
    return 0;
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "LNR: "; LNR(T);
	int i = isFullBinaryTree(T);
	if (i == 0) cout << "\nThe tree is not a Full Binary Tree";
	else cout << "\nThe tree is a Full Binary Tree";
	return 0;
}

