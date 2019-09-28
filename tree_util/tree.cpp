#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) { this->data=data; left=right=nullptr; }
};

void inorder(Node* nd) {
	if(!nd) return;
	inorder(nd->left);
	cout << nd->data << " ";
	inorder(nd->right);
}
void preorder(Node* nd) {
	if(!nd) return;
	cout << nd->data << " ";
	preorder(nd->left);
	preorder(nd->right);
}
void postorder(Node* nd) {
	if(!nd) return;
	postorder(nd->left);
	postorder(nd->right);
	cout << nd->data << " ";
}

void leftview(Node* nd) {
	if(!nd) return;
	cout << nd->data << " ";
	if(nd->left)
		leftview(nd->left);
	else if(nd->right)
		leftview(nd->right);
}

void rightview(Node* nd) {
	if(!nd) return;
	cout << nd->data << " ";
	if(nd->right)
		rightview(nd->right);
	else if(nd->left)
		rightview(nd->left);
}

int height(Node* nd) {
	if(!nd) return 0;
	int lH = height(nd->left);
	int rH = height(nd->right);
	return 1 + max(lH, rH);
}

int diameter(Node* nd) {
	if(!nd) return 0;
	int lh = height(nd->left);
	int rh = height(nd->right);
	int d = max(diameter(nd->left), diameter(nd->right));
	return max(lh+rh+1, d);
}

void printAllTrack(Node* nd) {
	static vector<Node*> S;
	if(!nd) return;
	S.push_back(nd);
	if(!nd->left && !nd->right) {
		for (auto it : S)
			cout << it->data << " ";
		cout << endl;
	}

	printAllTrack(nd->left);
	printAllTrack(nd->right);
	S.pop_back();
}

int main() {
	Node* root = new Node(50);
	root->left = new Node(30);
	root->right = new Node(70);
	root->left->left = new Node(20);
	root->left->left->right = new Node(25);
	root->left->right = new Node(40);
	root->right->left = new Node(60);
	root->right->left->right = new Node(65);
	root->right->left->right->left = new Node(62);
	root->right->right = new Node(80);

	cout << "inorder: ";
	inorder(root);
	cout << endl;
	cout << "preorder: ";
	preorder(root);
	cout << endl;
	cout << "postorder ";
	postorder(root);
	cout << endl;
	cout << "leftview: ";
	leftview(root);
	cout << endl;
	cout << "rightview: ";
	rightview(root);
	cout << endl;
	cout << "height: ";
	cout << height(root);
	cout << endl;
	cout << "diameter: ";
	cout << diameter(root);
	cout << endl;
	cout << "print all tracks: ";
	printAllTrack(root);
	cout << endl;
}
