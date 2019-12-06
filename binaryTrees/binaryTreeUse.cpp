#include <iostream>
#include <queue>
#include <climits> // for INT_MIN, INT_MAX, isBST(root)

//#include <pair> // for treeHeightBreadth(root), minMax(root)
using namespace std;

#include "binaryTreeNode.h"

/*
--------------------------------------------------------------------------------
	takes input level wise and returns root.
*/
binaryTreeNode<int>* takeInputLevelWise() {
	cout << "Enter root data : ";
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}

	binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);

	queue<binaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		binaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front -> data << ":";

		int leftChildData;
		cin >> leftChildData;

		// if left child data is given -1 then just return null.
		if(leftChildData != -1) {
			binaryTreeNode<int>* child = new binaryTreeNode<int>(leftChildData);
			front -> left = child;
			pendingNodes.push(child);
		}

		cout << "Enter right child of " << front->data << ":";
		int rightChildData;
		cin >> rightChildData;

		// if right child data is given -1 then just return null.
		if(rightChildData != -1) {
			binaryTreeNode<int>* child = new binaryTreeNode<int>(rightChildData);
			front -> right = child;
			pendingNodes.push(child);
		}
	}

	return root;
}


/*
--------------------------------------------------------------------------------
	takes input in a tree in recursive manner and returns root.
*/
binaryTreeNode<int>* takeInput() {
	cout << "Enter root data : ";
	int rootData;
	cin >> rootData;
	if(rootData == -1) {
		return NULL;
	}

	binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
	binaryTreeNode<int>* leftChild = takeInput();
	binaryTreeNode<int>* rightChild = takeInput();

	root->left = leftChild;
	root->right = rightChild;

	return root;
}

/*
--------------------------------------------------------------------------------
	prints binary tree level wise with left and right child of the node.
*/
void printBinaryTreeLevelWise(binaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}

	queue<binaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);

	while(pendingNodes.size() != 0) {
		binaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << front -> data << ":";
		if(front-> left != NULL) {
			cout << "L" << front -> left -> data << " ";
			pendingNodes.push(front->left);
		}

		if(front->right) {
			cout << "R" << front -> right -> data;
			pendingNodes.push(front->right);
		}
		cout << endl;
	}
}

/*
--------------------------------------------------------------------------------
	counts number of nodes in a binary tree.
*/
int numNodes(binaryTreeNode<int>* root) {
	if(root == NULL) {
		return 0;
	}

	return 1 + numNodes(root -> left) + numNodes(root -> right);
}


/*
--------------------------------------------------------------------------------
	prints Binary Tree with left and right child of the root.
*/
void printBinaryTree(binaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}

	cout << root->data << ":";

	if(root->left != NULL) {
		cout << "L" << root->left->data << " ";
	}

	if(root->right != NULL) {
		cout << "R" << root->right->data;
	}

	cout << endl;

	printBinaryTree(root->left);
	printBinaryTree(root->right);
}


/*
--------------------------------------------------------------------------------
	mirror of a binary tree
*/
void mirrorBinaryTree(binaryTreeNode<int>* root) {

    if(root == NULL) {
       return;
    }

    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);

    binaryTreeNode<int>* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

}

/*
--------------------------------------------------------------------------------
	inorder traversal(recursive) of a tree -> 1.left | 2.root | 3.right
*/
void inOrder(binaryTreeNode<int>* root) {
	if(root == NULL) {
		return;
	}

	inOrder(root -> left);
	cout << root -> data << " ";
	inOrder(root -> right);
}

/*
--------------------------------------------------------------------------------
	pre-order traversal(recursive) of a tree -> 1.root | 2.left | 3.right
*/
void preOrder(binaryTreeNode<int>* root) {

	if(root == NULL) {
		return;
	}

	cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

/*
--------------------------------------------------------------------------------
	post-order traversal(recursive) of a tree -> 1.left | 2. right | 3.root
*/
void postOrder(binaryTreeNode<int> *root) {

    if(root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

/* ------------------------------------------------------------------------------
 * creates a tree with preOrder and inOrder traversals of a tree.
 * takes preOrder and inOrder traversals in array as arguments.
 * returns root of binary tree created else returns NULL.
 * returns a root.
 *
 */
int findInorderRootIndex(int *arr, int toFind, int start, int end) {
    int i = start;
    for(; i <= end; i++) {
        if(arr[i] == toFind) {
            return i;
        }
    }
    return -1;
}

binaryTreeNode<int>* buildHelper(int *preorder, int *inorder, 
	int inStart, int inEnd, int preStart, int preEnd) {

    if(inStart > inEnd) {
        return NULL;
    }
    
    int rootData = preorder[preStart];
    
    int lInStart = inStart;
    int rootIndex = findInorderRootIndex(inorder, rootData, inStart, inEnd);
    int lInEnd = rootIndex - 1;
    int lPreStart = preStart + 1;
    int lPreEnd = (lInEnd - lInStart) + lPreStart;
    
    int rInStart = rootIndex + 1;
    int rInEnd = inEnd;
    int rPreStart = lPreEnd + 1;
    int rPreEnd = preEnd;
    
    binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
    root -> left = buildHelper(preorder, inorder, lInStart, lInEnd, lPreStart, lPreEnd);
    root -> right = buildHelper(preorder, inorder, rInStart, rInEnd, rPreStart, rPreEnd);
    
    return root;
}

binaryTreeNode<int>* buildTreePreOrderInOrder(int *preorder, int preLength, int *inorder, int inLength) {
    return buildHelper(preorder, inorder, 0, inLength-1, 0, preLength-1);
}


/*-----------------------------------------------------------------------------
 * build a tree with given postOrder and inOrder traversals of a tree.
 * takes postOrder and inOrder traversals in 
 * form of arrays and size of tree(int) as arguments.
 * returns root of tree built else returns returns NULL.
 * takes the help of helper function which takes 
 * start and end indexes in preOrder and postOrder traversals
 * of left and right sub-trees.
 * and buils a tree recursively.
 * TO USE -> 
 * buildTreePostOrderInOrder(<postOrder_trav_array>, <inOrder_trav_array>, <length of tree(int)>)
 */
binaryTreeNode<int>* buildHelperFromPostOrder(int *postOrder, int *inOrder, int inStart,
	int inEnd, int postStart, int postEnd) {

	if(inStart > inEnd) {
		return NULL;
	}

	int rootData = postOrder[postEnd];
	int rootIndex = findInorderRootIndex(inOrder, rootData, inStart, inEnd);

	int lInStart = inStart; //left inOrder start
	int lInEnd = rootIndex-1; // left inOrder end
	int lPostStart = postStart; // left postOrder start
	int lPostEnd = (lInEnd - lInStart) + lPostStart; // left postOder end

	int rInStart = rootIndex + 1;
	int rInEnd = inEnd;
	int rPostStart = lPostEnd + 1;
	int rPostEnd = postEnd - 1;

	binaryTreeNode<int>* root = new binaryTreeNode<int>(rootData);
	root -> left = buildHelperFromPostOrder(postOrder, inOrder, lInStart, lInEnd, lPostStart, lPostEnd);
	root -> right = buildHelperFromPostOrder(postOrder, inOrder, rInStart, rInEnd, rPostStart, rPostEnd);

	return root;
}


binaryTreeNode<int>* buildTreePostOrderInorder(int *postOrder, int *inOrder, int length) {
	/* take help of a helper function
	 * which will take traversals as well as 
	 * start and end index of subtrees.
	 * it will return root
	 */
	return buildHelperFromPostOrder(postOrder, inOrder, 0, length-1, 0, length-1);
}

/*------------------------------------------------------------------------------
 * find a breadth of a tree.
 * takes root of a tree as argument.
 * returns a pair <height, breadth> of a tree.
*/

pair<int, int> treeHeightBreadth(binaryTreeNode<int>* root) {
	/* base case -
	 * if root is NULL then, both 
	 * height and breadth are 0.
	 * pair = <first = height, sescond = breadth>
	 */
	if(root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	/* recursive calls on left and right sub-trees.
	 * get pairs for left and right sub-trees
	 */
	pair<int, int> leftAns = treeHeightBreadth(root -> left); // from left sub-tree.
	pair<int, int> rightAns = treeHeightBreadth(root -> right); // from right sub-tree.

	/* calculate total height and breadth using current node.
	*/
	int totalHeight = 1 + max(leftAns.first, rightAns.first);
	int totalBreadth =max(leftAns.first+ rightAns.first, max(leftAns.second, rightAns.second));

	/*make a separate pair ans to be returned.
	*/
	pair<int, int> ans;
	ans.first = totalHeight;
	ans.second = totalBreadth;

	return ans;
}

/*------------------------------------------------------------------------------
 * minMax(root) -
 * gives minimum and maximum node value
 * in a tree with recursive approach.
 * takes root as argument
 * return a pair of min & max value.
 * pair -> <first = min, second = max>
 * 
 */

pair<int, int> minMax(binaryTreeNode<int> *root) {
	pair<int, int> ans;
	ans.first =  2147483647; // numerical value of INT_MAX
	ans.second =  -2147483648; // numerical value of INT_MIN

	// base case1
	if(root == NULL) {
		return ans;
	}
	// base case2
	if(root -> left == NULL && root -> right == NULL) {
		ans.first = root -> data;
		ans.second = root -> data;
		return ans; 
	}

	// recursive steps on left and right subtree

	pair<int, int> leftAns = minMax(root -> left);
	pair<int, int> rightAns = minMax(root -> right);

	ans.first = min(root -> data, min(leftAns.first, rightAns.first));
	ans.second = max(root -> data, max(leftAns.second, rightAns.second));

	return ans;
}

/* ----------------------------------------------------------------------------
 * let us assume the given tree is
 * BST.
 * print all the nodes which are 
 * between k1 and k2 inclusively
 * in increasing ord(HINT : Tree is BST).
 * 
 * takes root and k1,k2 both int 
 * as funtion arguments
 * return type - void
 * prints all nodes between k1 & k2.
 * if exists(recursively).
 */
void printBetweenK1K2(binaryTreeNode<int> *root, int k1, int k2) {
	// base case.
	if(root == NULL || root -> data == -1) {
		return;
	}

	if(root -> data > k2) {
		printBetweenK1K2(root -> left, k1, k2);
	}

	if(root -> data < k1) {
		printBetweenK1K2(root -> right, k1, k2);
	}

	if(root -> data >= k1 && root -> data <= k2) {
		// if left node exists.
		if(root -> left) {
			printBetweenK1K2(root -> left, k1, k2);
		}
		/* in BST left < root <= right.
		 * so to print -
		 * left -> root -> right.
		 */
		cout << root -> data << " ";

		// if right node exist.
		if(root -> right) {
			printBetweenK1K2(root -> right, k1, k2);
		}
	}
	return;
}


/* -----------------------------------------------------------------------------
 * - checks if a given binary tree
 * is BST.
 * - isBST(root, min(int), max(int))
 * - takes root, min and max value
 * as arguments.
 * by default min & max are set to 
 * INT_MIN & INT_MAX respectively.
 * - constrains the range of min & max
 * for every node according to node
 * value, starting from INT_MIN, INT_MAX.
 * - return a boolean value 0 or 1.
 */

bool isBST(binaryTreeNode<int> * root, int min = INT_MIN,
	int max = INT_MAX) {

	// base case
	if(root == NULL) {
		return true; // null tree is BST
	}

	if(root -> data < min || root -> data > max) {
		return false;
	}

	/* recursive call on left subtree
	 * narrow the range constraint by 
	 * setting limit on max value.
	 */
	bool isBSTLeft = isBST(root -> left, min, root->data - 1);

	/* recursive call on right subtree
	 * narrow the range constraint by
	 * setting limit on min value
	 */
	bool isBSTRight = isBST(root->right, root-> data, max);

	return isBSTLeft && isBSTRight;
}


/*
--------------------------------------------------------------------------------
	main - driver function.
*/
int main() {
	/*  Tree -> 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
	binaryTreeNode<int>* root = new binaryTreeNode<int>(1);
	binaryTreeNode<int>* node1 = new binaryTreeNode<int>(2);
	binaryTreeNode<int>* node2 = new binaryTreeNode<int>(3);

	root -> left = node1;
	root -> right = node2;
	*/

	//binaryTreeNode<int>* root = takeInput();

	binaryTreeNode<int>* root = takeInputLevelWise();

	//printBinaryTree(root);

	printBinaryTreeLevelWise(root);

	cout << "Total no. of nodes : " << numNodes(root) << endl;

	//mirrorBinaryTree(root);

	cout << "in-order traversal : ";
	inOrder(root);
	cout << endl;

	cout << "pre-order traversal : ";
	preOrder(root);
	cout << endl;

	cout << "post-order traversal : ";
	postOrder(root);
	cout << endl;

	//printBinaryTreeLevelWise(root);

	if(isBST(root))
		cout << "IS BST!" << endl;
	else
		cout << "Not BST!" << endl;

	delete root;
}
