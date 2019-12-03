// Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/



node* skipMdeleteN(node *head, int M, int N) {
    // Write your code here
    if(head == NULL)
        return head;
    int mcount = 1;
    int ncount = 1;
    node *temp1 = head;
    node *temp2 = temp1;
    while(temp1 != NULL && temp2 != NULL) {
        while(mcount != M && temp1 -> next != NULL) {
            temp1 = temp1 -> next;
            mcount++;
        }
        
        temp2 = temp1 -> next;
        while(ncount != N && temp2 -> next != NULL) {
            node *toDel = temp2;
            temp2 = temp2 -> next;
            delete toDel;
            ncount++;
        }
        mcount = 1;
        ncount = 1;
        temp1 -> next = temp2 -> next;
        node *todel = temp2;
        temp2 = temp2 -> next;
        delete todel;
    }
    
    return head;
}

