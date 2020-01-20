#include "binaryTreeNode.h"

class BST {
	binaryTreeNode<int> *root;

public:
	BST() {
		root = NULL;
	}

	~BST() {
		delete root;
	}

	bool hasNode(int key);
	BST insert(int key);
	BST deleteNode(int key);

private:
	binaryTreeNode<int>* smallestInRight(binaryTreeNode<int>* node) {
		binaryTReeNode<int>* temp = node;
		while(temp && temp -> left != NULL) {
			temp = temp -> left;
		}
		return temp;
	}


	bool has(binaryTreeNode<int> *node, int key) {
		if(node == NULL) {
			return false;
		}

		if(node -> data == key) {
			return true;
		} else if(node -> data > key) {
			return has(root -> left, key);
		} else {
			return has(root -> right, key);
		}
	}

	binaryTreeNode<int>* insertPrivately(binaryTreeNode<int> *node, int key) {
		if(node == NULL) {
			binaryTreeNode<int> *newNode = new binaryTreeNode(key);
			root = newNode;
			return root; 
		}

		if(node -> data >= key) {
			node -> left = insertPrivately(node -> left, key);
		}
		else
			node -> right = insertPrivately(node -> right, key);

		return node;
	}



	binaryTreeNode<int>* deletePrivately(binaryTreeNode<int> *node, int key){
		if(node == NULL) {
			return NULL;
		}

		if(node -> data < key) {
			node -> right = deletePrivately(node -> right, key);
		}

		else if(node -> data > key) {
			node -> left = deletePrivately(node -> left, key);
		}

		else {
			if(node -> right == NULL) {
				binaryTreeNode<int>* newRoot = node -> left;
				delete node;
				return newRoot;
			}

			else if(node -> left == NULL) {
				binaryTreeNode<int>* newRoot = node -> right;
				delete node;
				return newRoot;
			}
			else {
				binaryTreeNode<int>* newRoot = smallestInRight(node -> right);
				node -> data = newRoot-> data;
				node -> right = deletePrivately(node -> right, newRoot -> data);
			}
			
		}
	}
};

binaryTreeNode<int>* BST::deleteNode(int key) {
	return deletePrivately(this -> root, key);
}

bool BST::hasNode(int key) {
	return has(this -> root, int key);
}

binaryTreeNode<int>* BST::insert(int key) {
	return insertPrivately(this -> root, key);
}