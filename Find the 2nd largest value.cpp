
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

void findSecondLargest(Node* T, int& secondLargest) {
	if (T == nullptr || (T->left == nullptr && T->right == nullptr)) {
		secondLargest = 0;
		return;
	}

	Node* current = T;
	Node* parent = nullptr;

	while (current->right != nullptr) {
		parent = current;
		current = current->right;
	}

	if (current->left != nullptr) {
		current = current->left;
		while (current->right != nullptr) {
			current = current->right;
		}
		secondLargest = current->info;
	}
	else {
		secondLargest = parent->info;
	}
}

void secondLargest(Tree& T) {
	int secondLargest;
	findSecondLargest(T, secondLargest);
	if (secondLargest == 0) {
		return;
	}
	else {
		cout << "2nd largest value is " << secondLargest << endl;
		return;
	}
}

int main()
{
	Tree T = NULL;
	inputTree(T);
	secondLargest(T);
	return 0;
}
