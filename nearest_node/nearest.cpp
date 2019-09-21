// recursive function to find key closeset to k
// in given BST
//
#include <iostream>

using namespace std;

int diff{100};
int minDiffKey{100};

struct Node {
    int key;
    Node* left;
    Node* right;
};

struct Node* newnode(int key) {
    Node* node = new Node();
    node->key=key;
    node->left = node->right = nullptr;
    return node;
}

void minDiff(Node *nd, int k) {
    if(nd == nullptr)
        return;

    if(nd->key == k) {
        minDiffKey = k;
        return;
    }

    if(diff > abs(nd->key - k)) {
        diff = abs(nd->key - k);
        minDiffKey = nd->key;
    }

    if(k < nd->key)
        minDiff(nd->left, k);
    else
        minDiff(nd->right, k);
}

int main() {
    Node* root = newnode(9);
    root->left = newnode(4);
    root->right = newnode(17);
    root->left->left = newnode(3);
    root->left->right = newnode(6);
    root->left->right->left = newnode(5);
    root->left->right->right = newnode(7);
    root->right->right = newnode(22);
    root->right->right->left = newnode(20);

    int k = 18;
    cout << ::diff << " " << minDiffKey << endl;
    minDiff(root, k);
    cout << diff << " " << minDiffKey << endl;
}

