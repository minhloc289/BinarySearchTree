
#include <iostream>
using namespace std;

struct Node
{
    int info;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node* Tree;

Node* getNode(int x);
void insertNode(Tree& T, int x);
void inputTree(Tree& T);
void NLR(Tree T);
bool isSquare(int n);
void SearchStandFor(Node*& p, Node*& q); //Chon node phai nhat tren nhanh con ben trai
void deleteSquareNumbers(Tree& T);


Tree getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void InsertNode(Tree& T, int x) {
    if (T != NULL) {
        if (x < T->info) {
            InsertNode(T->pLeft, x);
        }
        else if (x > T->info) {
            InsertNode(T->pRight, x);
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
        InsertNode(T, x);
    }
}

void NLR(Tree T) {
    if (T) {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

bool isSquare(int n) {
    int i = 1;
    if (n < 1) {
        return false;
    }
    while (i * i <= n) {
        if (i * i == n) {
            return true;
        }
        i++;
    }
    return false;
}

void SearchStandFor(Node*& p, Node*& q) {
    if (q->pRight != NULL) {
        SearchStandFor(p, q->pRight);
    }
    else {
        p->info = q->info;
        p = q;
        q = q->pLeft;
    }
}

void deleteSquareNumbers(Tree& T) {
    if (T == NULL) {
        return;
    }
    deleteSquareNumbers(T->pLeft);
    deleteSquareNumbers(T->pRight);
        if (isSquare(T->info)) {
            Node* p = T;
            if (T->pLeft == NULL) {
                T = T->pRight;
            }
            else if (T->pRight == NULL) {
                T = T->pLeft;
            }
            else {
                SearchStandFor(p, T->pLeft);
            }
            delete p;
        }
}

int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: "; NLR(T);
    cout << "\nDelete all square numbers:";
    deleteSquareNumbers(T);
    cout << "\nNLR: "; NLR(T);

    return 0;
}
