
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

int height(Tree T) {
	if (T == NULL) {
		return -1;
	}
	int leftHeight = height(T->left);
	int rightHeight = height(T->right);
	return max(leftHeight, rightHeight) + 1;
}

int checkLeaves(Tree T, int h, int level) {
	if (T == NULL) {
		return 1;
	}
	if (T->left == NULL && T->right == NULL && level == h) {
		return 1;
	}
	if (T->left == NULL || T->right == NULL) {
		return 0;
	}
	return checkLeaves(T->left, h, level + 1) && checkLeaves(T->right, h, level + 1);
}



int isFullBinaryTree(Tree T) {
	if (T == NULL) {
		return 1;
	}
	if (T->left == NULL && T->right == NULL) {
		return 1;
	}
	if (T->left != NULL && T->right != NULL) {
		int left = isFullBinaryTree(T->left);
		int right = isFullBinaryTree(T->right);
		if (left && right) {
			return 1;
		}
	}
	return 0;
}

int isCompleteBinaryTree(Tree T) {
	if (T == NULL) {
		return 1;
	}
	int h = height(T);
	int isFull = isFullBinaryTree(T);
	if (!isFull) {
		return 0;
	}
	return checkLeaves(T, h, 1);
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	cout << "LNR: "; LNR(T);
	int i = isCompleteBinaryTree(T);
	if (i == 0) cout << "\nThe tree is not a Complete Binary Tree";
	else cout << "\nThe tree is a Complete Binary Tree";
	return 0;
}


