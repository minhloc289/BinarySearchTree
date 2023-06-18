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

bool isExist(Tree& T, int x) {
	if (T == NULL) {
		return false;
	}
	else if (x == T->info) {
		return true;
	}
	else if (x < T->info) {
		return isExist(T->left, x);
	}
	else {
		return isExist(T->right, x);
	}
}

void inputTree(Tree& T) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (isExist(T,x)) {
			cout << "Bi trung gia tri, ket thuc qua trinh tao cay" << endl;
			return;
		}
		else {
			InsertTree(T, x);
		}
	}
}

void NLR(Tree T) {
	if (T) {
		cout << T->info << " ";
		NLR(T->left);
		NLR(T->right);
	}
}



int main()
{
	Tree T = NULL;
	inputTree(T); //Khi bi trung gia tri thi ket thuc qua trinh tao cay, khong nhap tiep nua
	cout << "NLR: "; NLR(T);
	return 0;
}





