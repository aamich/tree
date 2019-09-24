// recursive function to print tree bounday 
// in given BST
//
#include <iostream>

using namespace std;

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

void printLeftB(Node* nd) {
    if(!nd)
        return;

    if(nd->left) {
        cout << nd->key << " ";
        printLeftB(nd->left);
    }
    else if(nd->right) {
        cout << nd->key << " ";
        printLeftB(nd->left);
    }
}

void printRightB(Node* nd) {
    if(!nd)
        return;

    if(nd->right) {
        cout << nd->key << " ";
        printRightB(nd->right);
    }
    else if(nd->left) {
        cout << nd->key << " ";
        printRightB(nd->right);
    }
}

void printLeafB(Node* nd) {
    if(!nd)
        return;

    printLeafB(nd->left);
    if(!nd->left && !nd->right)
        cout << nd->key << " ";
    printLeafB(nd->right);
}

void dfs(Node* nd) {
    if(!nd)
        return;
    cout << nd->key << " ";
    dfs(nd->left);
//    if(nd->left && nd->right)
//        cout << nd->key << " ";
    dfs(nd->right);
}


void dfs2(Node* nd) {
    if(!nd)
        return;
    cout << nd->key << " ";
    dfs2(nd->left);
    if(nd->left && nd->right)
        cout << nd->key << " ";
    dfs2(nd->right);
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

    cout << "dfs:" << endl;
    dfs(root);
    cout << endl;

    cout << "dfs with connecting node repeated:" << endl;
    dfs2(root);
    cout << endl;

    cout << "left boundary:" << endl;
    printLeftB(root);
    cout << endl;
    cout << "right boundary" << endl;
    printRightB(root);
    cout << endl;
    cout << "leaf boundary" << endl;
    printLeafB(root);
    cout << endl;
}

