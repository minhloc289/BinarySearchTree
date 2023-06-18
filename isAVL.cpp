#include <iostream>
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

int height(Tree T) {
    if (T == NULL) return -1;
    return max(height(T->left), height(T->right)) + 1;
}

bool isAVL(Tree T) {
    if (T == NULL) return true;
    int leftHeight = height(T->left);
    int rightHeight = height(T->right);
    if (abs(leftHeight - rightHeight) > 1) return false;
    return isAVL(T->left) && isAVL(T->right);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << isAVL(T);
	return 0;
}
