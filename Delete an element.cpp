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

void NLR(Tree T) {
    if (T) {
        cout << T->info << " ";
        NLR(T->left);
        NLR(T->right);
    }
}

Tree findMin(Tree T) {
    if (T == NULL) return NULL;
    if (T->left == NULL) return T;
    return findMin(T->left);
}

void deleteNode(Tree& T, int x) {
    if (T == NULL) return;
    if (x < T->info) {
        deleteNode(T->left, x);
    }
    else if (x > T->info) {
        deleteNode(T->right, x);
    }
    else {
        if (T->left == NULL && T->right == NULL) {
            delete T;
            T = NULL;
        }
        else if (T->left == NULL) {
            Tree tmp = T;
            T = T->right;
            delete tmp;
        }
        else if (T->right == NULL) {
            Tree tmp = T;
            T = T->left;
            delete tmp;
        }
        else {
            Tree tmp = findMin(T->right);
            T->info = tmp->info;
            deleteNode(T->right, tmp->info);
        }
    }
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "NLR: "; NLR(T);
	int x; cout << "\nEnter the element you want to delete: "; cin >> x;
	deleteNode(T, x);
	cout << "\nNLR: "; NLR(T);

	return 0;
}
