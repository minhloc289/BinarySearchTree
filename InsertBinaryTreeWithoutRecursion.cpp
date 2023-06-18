
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void preOrder(Node* root) {

        if (root == NULL)
            return;

        std::cout << root->data << " ";

        preOrder(root->left);
        preOrder(root->right);
    }

    /* you only have to complete the function given below.
    Node is defined as

    class Node {
        public:
            int data;
            Node *left;
            Node *right;
            Node(int d) {
                data = d;
                left = NULL;
                right = NULL;
            }
    };

    */

    Node* insert(Node* root, int data) {
        Node* newNode = new Node(data);

        if (root == NULL)
            return newNode;

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;

            if (data <= current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (data <= parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;

        return root;
    }
};

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
