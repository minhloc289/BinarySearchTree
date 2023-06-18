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

void LNR(Tree& T) {
    if (T) {
        LNR(T->left);
        cout << T->info << " ";
        LNR(T->right);
    }
}

int countNodes(Tree& T) {
    if (T == NULL) {
        return 0;
    }
    else {
        return 1 + countNodes(T->left) + countNodes(T->right);
    }
}

int depthOfTree(Tree& T) {
    if (T == NULL || (T->left == NULL && T->right == NULL)) {
        return 0;
    }
    else {
        int left = depthOfTree(T->left);
        int right = depthOfTree(T->right);
        if (left > right) {
            return (left + 1);
        }
        else {
            return (right + 1);
        }
    }
}

void countEven(Tree& T, int& count_even) {
    if (T == NULL) {
        return;
    }
    if (T->info % 2 == 0) {
        count_even++;
    }

    countEven(T->left, count_even);
    countEven(T->right, count_even);
}

void countOdd(Tree& T, int& count_odd) {
    if (T == NULL) {
        return;
    }
    if (T->info % 2 != 0) {
        count_odd++;
    }

    countOdd(T->left, count_odd);
    countOdd(T->right, count_odd);
}

int countPositive(Tree& T) {
    int count = 0;
    if (T == NULL) {
        return 0;
    }
    if (T->info > 0) {
        count++;
    }

    count += countPositive(T->left);
    count += countPositive(T->right);

    return count;
}

int countNegative(Tree& T) {
    int count = 0;
    if (T == NULL) {
        return 0;
    }
    if (T->info < 0) {
        count++;
    }

    count += countNegative(T->left);
    count += countNegative(T->right);

    return count;
}

bool PrimeNumbers(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i  <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrime(Tree& T) {
    int count = 0;
    if (T == NULL) {
        return 0;
    }
    if (PrimeNumbers(T->info)) {
        count++;
    }

    count += countPrime(T->left);
    count += countPrime(T->right);
    return count;
}

void listPrime(Tree& T) {
    if (T == NULL) {
        return;
    }
    if (PrimeNumbers(T->info)) {
        cout << T->info << " ";
    }

    listPrime(T->left);
    listPrime(T->right);
}
int main()
{
    Tree T = NULL;
    inputTree(T);
    cout << "LNR: "; LNR(T); cout << endl;

    cout << "Number of nodes: " << countNodes(T) << endl;
    cout << "Depth of Tree: " << depthOfTree(T) << endl;

    int count_even = 0, count_odd = 0;
    countEven(T, count_even); countOdd(T, count_odd);
    cout << "Number of even nodes: " << count_even << endl;
    cout << "Number of odd nodes: " << count_odd << endl;

    cout << "Number of positive nodes: " << countPositive(T) << endl;
    cout << "Number of negative nodes: " << countNegative(T) << endl;

    cout << "Number of prime nodes: " << countPrime(T) << endl;
    cout << "Prime numbers: "; listPrime(T);



    return 0;
}
