#ifndef TREENODE_H
#define TREENODE_H
#include <vector>
using namespace std;

template <typename T>
class treeNode {
    public :

    T data;
    vector<treeNode<T>*> children;

    treeNode(T data) {
        this -> data = data;
    }

    ~treeNode() {
    	for(int i = 0; i < children.size(); i++) {
    		/* does not delete object until it's destructor function is fully executed.
			   so it uses recursion.
			*/
    		delete children[i]; 
    	}
    }
};
#endif
