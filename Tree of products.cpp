
#include <iostream>
#include <string>
using namespace std;

struct Product {
    int id;
    string name;
    string type;
    int year;
    int warranty;
};

struct Node {
    Product info;
    Node* left, * right;
};
typedef Node* Tree;

void getNode(Tree& T, Product x) {
    if (T == NULL) {
        Node* p = new Node;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        T = p;
    }
    else if (x.id < T->info.id) {
        getNode(T->left, x);
    }
    else if (x.id > T->info.id) {
        getNode(T->right, x);
    }
}

void inputProduct(Product& x) {
    cin >> x.id;
    cin.ignore();
    getline(cin, x.name);
    getline(cin, x.type);
    cin >> x.year;
    cin >> x.warranty;
}


void inputTree(Tree& T) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        Product x;
        inputProduct(x);
        getNode(T,x);
    }
}

void listProduct(Tree T, string typee) {
    if (T != NULL) {
        listProduct(T->left, typee);
        if (T->info.type == typee) {
            cout << T->info.id << " " << T->info.name << " " << T->info.type << " " << T->info.year << " " << T->info.warranty << endl;
        }
        listProduct(T->right, typee);
    }
}

int countProduct(Tree& T, int yearr) {
    if (T == NULL) {
        return 0;
    }
    else if (T->info.warranty > yearr) {
        return 1 + countProduct(T->left, yearr) + countProduct(T->right, yearr);
    }
    else {
        return countProduct(T->left, yearr) + countProduct(T->right, yearr);
    }
}

int main()
{
    Tree T = NULL;
    inputTree(T);

    string type;  cin.ignore(); getline(cin, type);
    cout << "List of products whose type is  " << type << ": ";
    cout << "\nID\tName\tType\tYear\tWarranty\n";
    listProduct(T, type);

    int year; cin >> year;
    cout << "Number of products with more than " << year << " years of warranty: " << countProduct(T, year) << endl;


    return 0;
}

