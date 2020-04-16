#include "binaryTreeUse.cpp"

void printInorderIter(binaryTreeNode<int>* root) {
	// inorder traversal
}

void printPreOrderIter(binaryTreeNode<int>* root) {
	// pre order traversal
}

void printPostOrderIter(binaryTreeNode<int>* root) {
	// post order traversal
}

int main() {
	#warning "There is main funtion in binaryTreeUse.cpp. so comment it out to use this file."
	// start to write code from here
	
	binaryTreeNode<int>* root = takeInputLevelWise();
	
	// TODO: implement inorder, preOrder and levelOrder traversal
	// in iterative way.
	
	printInorderIter(root);
	printPreOrderIter(root);
	printPostOrderIter(root);
	
	
	return 0;
}
