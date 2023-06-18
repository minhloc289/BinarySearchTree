
#include <iostream>
using namespace std;

typedef struct Node {
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

void LNR(Tree T) {
    if (T) {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

Tree Search(Tree& T, int x) {
    if (T == NULL || T->info == x) {
        return T;
    }

    if (T->info < x) {
        return Search(T->right, x);
    }

    if (T->info > x) {
        return Search(T->left, x);
    }
}

int minValue(Tree& T) {
    if (T->left == NULL) {
        return T->info;
    }

    return minValue(T->left);
}

int maxValue(Tree& T) {
    if (T->right == NULL) {
        return T->info;
    }

    return maxValue(T->right);
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;


    int x; cout << "\nEnter the element you want to find: "; cin >> x;
    Node* p = Search(T, x);
    if (p) cout << "Found";
    else cout << "Not found";
    cout << "\nMinimum value in BTS is " << minValue(T);
    cout << "\nMinimax value in BTS is " << maxValue(T);


    return 0;
}
