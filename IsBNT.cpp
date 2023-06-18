
#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left, * right;
    Node(int x) : info(x), left(nullptr), right(nullptr) {}
}; typedef Node* Tree;


Node* getNode(int x) {
    Node* temp = new Node(x);
    return temp;
}


Tree SetLeft(Tree T, int x) {
    if (T == NULL) {
        cout << "Node khong ton tai\n";
        return T;
    }
    if (T->left == NULL) {
        T->left = getNode(x);
    }
    else {
        cout << "Da co node con ben trai\n";
    }
    return T;
}

Tree SetRight(Tree T, int x) {
    if (T == NULL) {
        cout << "Node khong ton tai\n";
        return T;
    }
    if (T->right == NULL) {
        T->right = getNode(x);
    }
    else {
        cout << "Da co node con ben phai\n";
    }
    return T;
}

Tree Search(Tree T, int x)
{
    if (T == NULL)
        return NULL;
    if (T->info == x)
        return T;
    Node* q;
    q = Search(T->left, x);
    if (q == NULL)
        q = Search(T->right, x);
    return q;
}

void LNR(Tree T) {
    if (T) {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

bool isBST(Tree T, int* min, int* max) {
    if (T == NULL) return true;
    if ((min != NULL && T->info <= *min) || (max != NULL && T->info >= *max)) return false;
    return isBST(T->left, min, &(T->info)) && isBST(T->right, &(T->info), max);
}

bool isBST(Tree T) {
    return isBST(T, NULL, NULL);
}


int main()
{
    Tree T = NULL;
    int x, b, c; char a;
    cin >> x;	T = getNode(x); // tao nut goc
    while (true)
    {
        cin >> a; // Ky tu cho biet chen vao trai hay phai
        if (a != 'L' && a != 'R') break; // Neu khong phai L hoac R thi ket thuc viec tao cay
        cin >> b >> c;
        if (a == 'L') SetLeft(Search(T, b), c); // chen c vao ben trai b
        else if (a == 'R') SetRight(Search(T, b), c); // chen c vao ben phai b
    }
    cout << "\nLNR: "; LNR(T); cout << endl;
    if (isBST(T)) cout << "\Cay vua tao la cay BST";
    else cout << "\Cay vua tao khong phai la cay BST";

    return 0;
}
