#include <bits/stdc++.h>
using namespace std;

#include "nodeClass.cpp"

/* ** procedure to insert a data "data" at postion "pos".
*/

Node *insertAt(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    if(pos == 0)
    {
        newNode -> next = head;
        return newNode;
    }
    Node *temp = head;
    int count = 0;
    while(temp != NULL && count < pos-1)
    {
        temp = temp -> next;
        count++;
    }
    if(temp != NULL)
    {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
    return head;
}
/*
class Pair {
    public :
        Node *head = NULL;
        Node *tail = NULL;
};

// recursive O(N) algo. Returns both head and tail.
Pair giveReversedPair(Node *head) {
    if(head == NULL || head -> next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = giveReversedPair(head -> next);

    smallAns.tail -> next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

// actual function to call to reverse a linked list recursively
Node *reverseLinkedList(Node *head)
{
    return giveReversedPair(head).head;
}
*/

// O(n) algo to recursively reverse a linked list.
Node *reverseLLRecursive(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLLRecursive(head -> next);

    Node *tail1 = head -> next;
    tail1 -> next = head;
    head -> next = NULL;
    return newHead;
}

/* ** procedure to reverse a linked list
*/

Node *reverseLLIter(Node *head)
{
    Node *current = head;
    Node *previous = NULL, *next = NULL;
    while(current != NULL)
    {
        next = current -> next;
        current -> next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

Node* skipMdeleteN(Node *head, int M, int N) {
    // Write your code here
    if(head == NULL)
        return head;
    int mcount = 1;
    int ncount = 1;
    Node *temp1 = head;
    // Node *temp2 = temp1;
    while(temp1 != NULL) {
        while(mcount != M && temp1 != NULL) {
            temp1 = temp1 -> next;
            mcount++;
        }

        Node *temp2 = temp1 -> next;
		temp1 -> next = NULL;
        while(ncount != N && temp2 != NULL) {
            Node *toDel = temp2;
            temp2 = temp2 -> next;
            delete toDel;
            ncount++;
        }
        mcount = 1;
        ncount = 1;
		if(temp1 != NULL && temp2 != NULL) {
        	temp1 -> next = temp2 -> next;
			temp1 = temp1 -> next;
        	Node *todel = temp2;
        	temp2 = temp2 -> next;
        	delete todel;
		}
    }

    return head;
}

/** procedure to swap two node
*/

Node* swap_nodes(node *head,int i,int j)
{
    //write your code here
    int count = 0;
    int small = i < j ? i : j;
    int large = (i == small) ? j : i;

    Node *smallptr = head;
    Node *largeptr = head;

    while(count != small)
    {
        smallptr = smallptr -> next;
        count++;
    }

    count = 0;

    while(count != large)
    {
        largeptr = largeptr -> next;
        count++;
    }

    if((small == 0 || large == 0) && (large - small == 1))
    {
        smallptr -> next = largeptr -> next;
        largeptr -> next = smallptr;
        return largeptr;
    }

    Node *prevlarge = head; count = 0;
    while(count != large-1)
    {
        prevlarge = prevlarge -> next;
        count++;
    }

    if(small == 0 || large == 0)
    {
        prevlarge -> next = smallptr;
        Node *temp = smallptr -> next;
        smallptr -> next = largeptr -> next;
        largeptr -> next = temp;
        return largeptr;
    }

    Node *prevsmall = head; count = 0;
    while(count != small - 1)
    {
        prevsmall = prevsmall -> next;
        count++;
    }

    if(large - small == 1)
    {
        prevsmall -> next = largeptr;
        smallptr -> next = largeptr -> next;
        largeptr -> next = smallptr;
        return head;
    }

    prevsmall -> next = largeptr;
    prevlarge -> next = smallptr;
    Node *temp = smallptr -> next;
    smallptr -> next = largeptr -> next;
    largeptr -> next = temp;

    return head;
}


/* ** procedure to perform bubble sort
*/

Node* bubbleSort(Node *head)
{
    Node *temp = head;
    while(temp -> next != NULL)
    {
        Node *temp2 = temp;
        while(temp2 -> next != NULL)
        {
            if(temp2 -> data > temp2 -> next -> data)
            {
                temp2 = swap_nodes(temp, 0, 1);
            }
            temp2 = temp2 -> next;
        }
    }
}


/* ** procedure to create a Linked List
*/

void createLinkedList(LinkedList &list)
{
    int data;
    cin >> data;
    while(data != -1)
    {
        list.insertNode(data);
        cin >> data;
    }
}

/* ** procedure to print linked list
*/

void printLinkedList(Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << "\n";
}

/* ** procedure to free a linked list
*/

void freeLinkedList(Node *head)
{
    while(head != NULL)
    {
        Node *temp = head;
        head = head -> next;
        free(temp);
    }
}

int main()
{
    LinkedList list1;
    createLinkedList(list1);
    printLinkedList(list1.head);

    //list1.head = insertAt(list1.head, 4, 55);
    //printLinkedList(list1.head);

    //list1.head = reverseLinkedList(list1.head);
    //printLinkedList(list1.head);

    //list1.head = reverseLLRecursive(list1.head);
    //printLinkedList(list1.head);

    //list1.head = reverseLLIter(list1.head);
    //printLinkedList(list1.head);

	int N, M;
	cin >> M>> N;

	list1.head = skipMdeleteN(list1.head, M, N);
	printLinkedList(list1.head);
    /*
    LinkedList list2;
    createLinkedList(list2);
    printLinkedList(list2.head);

    freeLinkedList(list1.head);
    freeLinkedList(list2.head);
    */
}
