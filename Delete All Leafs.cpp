
#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* left, * right;
}; typedef Node* Tree;

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
			return InsertTree(T->left, x);
		}
		else if (x > T->info) {
			return InsertTree(T->right, x);
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

Tree removeLeafs(Tree& T) {
	if (T) {
		if (T->left == NULL && T->right == NULL) {
			delete T;
			return NULL;
		}
		else {
			T->left = removeLeafs(T->left);
			T->right = removeLeafs(T->right);
		}
	}
	return T;
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "LNR: "; LNR(T);
	T = removeLeafs(T);
	cout << "\nUpdated Tree: \n";
	cout << "LNR: "; LNR(T);
	return 0;
}



