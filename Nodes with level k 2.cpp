
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
int nodesWithLevel(Tree T, int k, int c);

Node* getNode(int x) {
    Node* p = new Node;
    p->info = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void insertNode(Tree& T, int x) {
    if (T == NULL) {
        T = getNode(x);
    }
    else {
        if (x < T->info) {
            insertNode(T->pLeft, x);
        }
        else if (x > T->info) {
            insertNode(T->pRight, x);
        }
    }
}

void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertNode(T, x);
    }
}

void NLR(Tree T) {
    if (T) {
        cout << T->info << " ";
        NLR(T->pLeft);
        NLR(T->pRight);
    }
}

int nodesWithLevel(Tree T, int k, int c) {
    static int printedCount = 0; 
    int count = 0;
    if (T == NULL) {
        return count;
    }
    count += nodesWithLevel(T->pRight, k, c + 1);
    count += nodesWithLevel(T->pLeft, k, c + 1);

    if (c == k && T != NULL) { 
        if (printedCount == 0) { 
            cout << "\nList of nodes with level " << k << " (R->L): " << T->info << " ";
            printedCount++;
        }
        else { 
            cout << T->info << " ";
        }
        count++;
    }
    if (c == 0 && printedCount == 0 && count == 0) {
        cout << "\nList of nodes with level " << k << " (R->L): ";
        printedCount++;
    }
    if (c == 0 && printedCount == 1) { 
        cout << "\nNumber of nodes with level " << k << ": ";
    }
    return count;
}


int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "\nNLR: "; NLR(T);
    int k; cout << "\nEnter k: "; cin >> k;
    cout << nodesWithLevel(T, k, 0); //neu tham so thu 3 khong can dung thi trong ham khong can xu ly

    return 0;
}
