#include <iostream>
#include <queue>
#include "treeNode.h"

using namespace std;

/* takes no argument.
 * returns root of tree formed.
 * this function helps to take input of tree level-wis.
 * 
 * uses queue to take input level wise until that queue is empty.
 */
treeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "enter root data : " << endl;
    cin >> rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    queue<treeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        treeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter numbers of children's of " << front -> data << endl;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int chilData;
            cout << "enter " << i+1 << "th child of " << front -> data << endl;
            cin >> chilData;
            treeNode<int>* child = new treeNode<int>(chilData);
            front -> children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

treeNode<int>* takeInput() {
    int rootData;
    cout << "enter data : " ;
    cin >> rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout << "\nenter number if child of " << rootData << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        treeNode<int>* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

void printLevelWise(treeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    queue<treeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0) {
        treeNode<int>* front = pendingNodes.front();
        cout << front -> data << ":";
        pendingNodes.pop();
        int n = front -> children.size();
        for(int i = 0; i < n; i++) {
            cout << front -> children[i] -> data << ",";
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

void printTree(treeNode<int>* root) {

    if(root == NULL) {
        return;
    }


    cout << root -> data << ":";
    // for printing all children's of a node
    for(int i = 0; i < root -> children.size(); i++) {
        cout << root -> children[i] -> data << ",";
    }

    cout << endl;

    for(int i = 0; i < root -> children.size(); i++) {
        printTree(root -> children[i]);
    }
}

// returns count of total no. of nodes in a tree.
int countNodes(treeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 1;
    for(int i = 0; i < root -> children.size(); i++) {
        ans += countNodes(root -> children[i]);
    }
    return ans;
}

// returns total sum of all node's data.
int getSum(treeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    int sum = root -> data;
    for(int i = 0; i < root -> children.size(); i++) {
        sum += getSum(root -> children[i]);
    }
    return sum;
}

// returns a node with maximum data value.
treeNode<int>* maxDataNode(treeNode<int>* root) {
    if(root == NULL) {
        return root;
    }

    treeNode<int>* max = root;
    for(int i = 0; i < root -> children.size(); i++) {
        treeNode<int>* smallAns = maxDataNode(root -> children[i]);
        if((smallAns -> data) > (max -> data)) {
            max = smallAns;
        }
    }
    return max;
}

/*
    helper class and function to get second largest element in a tree
	if present.
*/
class Pair {
	public :
	treeNode<int>* largest;
	treeNode<int>* secLargest;

}
// function
Pair getSecondLargest(treeNode<int>* root) {
	/*if(root == NULL) {
		return 0;
	}
	*/
	Pair ans;
	ans.largest = root;
	ans.secLargest = NULL;

	for(int i = 0; i < root -> children.size(); i++) {
		Pair temp = getSecondLargest(root -> children[i]);

		if(temp.largest -> data > ans.largest -> data) {
			treeNode<int>* x = ans -> largest;
			ans.largest = temp.largest;
			if(ans.secLargest == NULL) {
				if(temp.secLargest == NULL) {
					ans.secLargest = x;
				}
				else {
					ans.secLargest = (x -> data > temp.secLargest -> data) ? x : temp.secLargest;
				}
			}
			else {
				if(temp.secLargest == NULL) {
					ans.secLargest = x;
				}
				else {
					ans.secLargest = (x -> data > temp.secLargest -> data) ? x : temp.secLargest;
				}
			}
		}


		else {
			if(ans.secLargest == NULL) {
				ans.secLargest = temp.largest;
			}
			else if((temp.largest -> data) > (ans.secLargest -> data)) {
				ans.secLargest = temp.largest;
			}
		}
	}

	return ans;
}

/*
	returns second largest element if present in the tree
    else returns NULL.
*/
treeNode<int>* secondLargest(treeNode<int>* root) {

	return getSecondLargest(root).secLargest;

}

/* returns node with maximum child sum.
   also can use a pair class 
   which will help to return node as well as its sum together. and get rid of
   calculating child's node sum twice.
*/
treeNode<int>* maxSumNode(treeNode<int> *root) {

    int ans = root -> data; // set ans as root node.

    // get sum of root node.
    for(int i = 0; i < root -> children.size(); i++) {
        ans += root -> children[i] -> data;
    }

    // ans node to be returned.
    treeNode<int>* ansNode = root;
 
 	// check if any child has greater sum than root.
    for(int i = 0; i < root -> children.size(); i++) {
    	// get a child node which has maximum sum along with its children.
        treeNode<int>* maxSumChild = maxSumNode(root -> children[i]); // recursive step.

        // get sum of maximum sum child node.
        int childNodeSum = maxSumChild -> data;

        for(int i = 0; i < maxSumChild -> children.size(); i++) {
            childNodeSum += maxSumChild -> children[i] -> data;
        }

        // check if it is greater than previous ans.
        if(childNodeSum > ans) {
            ans = childNodeSum;
            ansNode = maxSumChild;
        }
    }

    return ansNode;
}

/* returns maximum heigth of a tree.
 * takes root of 'treeNode<int>*' type as argument.
 * returns integral value of height.
 * returns 0 if root is equal to NULL.
 */
int getHeight(treeNode<int>* root) {
    /* check if root is NULL.
     * if yes then return 0
     */
    if(root == NULL) {
        return 0;
    }

    int max = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        int smallAns = getHeight(root -> children[i]);
        if(smallAns > max) {
            max = smallAns;
        }
    }

    return max+1;
}

// prints all node's data which are at level k
void printAtLevelK(treeNode<int>* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout << root -> data << endl;
        return;
    }

    for(int i = 0; i < root -> children.size(); i++) {
        printAtLevelK(root -> children[i], k-1);
    }
}

int getTotalLeaves(treeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    if(root -> children.size() == 0) {
        return 1;
    }
    int count = 0;
    for(int i = 0; i < root -> children.size(); i++) {
        count += getTotalLeaves(root -> children[i]);
    }
    return count;
}

void preOrder(treeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    // Print root first
    cout << root -> data << " ";
    for(int i = 0; i < root -> children.size(); i++) {
        preOrder(root -> children[i]);
    }
}

void postOrder(treeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    // print childs first
    for(int i = 0; i < root -> children.size(); i++) {
        postOrder(root -> children[i]);
    }

    cout << root -> data << " ";
}

// to identify if two trees are structurally identical.
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    if(root1 -> data != root2 -> data) {
        return false;
    }
    if(root1 -> children.size() != root2 -> children.size()) {
        return false;
    }

    bool smallAns = true;

    for(int i = 0; i < root1 -> children.size(); i++) {
        smallAns = isIdentical(root1 -> children[i], root2 -> children[i]);
        if(!smallAns) {
            return false;
        }
    }

    return smallAns;
}


/*to delete whole tree. also see "treeNode.h" for an alternative
  which uses destructor to delete the tree.
  "code - delete root;"
*/
void deleteTree(treeNode<int>* root) {
    if(root == NULL) {
        return;
    }

    for(int i = 0; i < root -> children.size(); i++) {
        deleteTree(root -> children[i]);
    }
    delete root;
}

int main() {
    /*treeNode<int>* root = new treeNode<int>(1);
    treeNode<int>* node1 = new treeNode<int>(2);
    treeNode<int>* node2 = new treeNode<int>(3);
    root -> children.push_back(node1);
    root -> children.push_back(node2);
    */
    //treeNode<int>* root = takeInput();
    treeNode<int>* root = takeInputLevelWise();

    //printTree(root);
    printLevelWise(root);

    cout << "sum : " << getSum(root) << endl;

    cout << "number of nodes : " << countNodes(root) << endl;
    
    deleteTree(root); // or use "delete root" -> uses destructor, see "treeNode.h" line 15.

}
