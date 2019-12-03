// class to create new node
class Node
{
    public :
        int data;
        Node *next;

        Node(int data)
        {
            this -> data = data;
            this -> next = NULL;
        }
};

// class to create a linked list.
class LinkedList
{
    public :
        Node *head;
        Node *tail;

        LinkedList()
        {
            this -> head = NULL;
            this -> tail = NULL;
        }

        void insertNode(int data)
        {
            Node *node = new Node(data);

            if(!this -> head)
            {
                this -> head = node;
            }
            else
            {
                this -> tail -> next = node;
            }
            this -> tail = node;
        }
};
