template <typename T>
class Node {
    T data;
    Node<T> *next;
    public :

    Node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int length;
    public :

    Stack() {
        this -> head = NULL;
        this -> length = 0;
    }

    // O(1)
    void push(T data) {
        Node<T> *temp = new Node<T>(data);
        temp -> next = head;
        head = temp;
        length++;
    }

    T top() {
        if(isEmpty()) {
            cout << "stack is empty!" << endl;
            return 0;

        }
        return head -> data;
    }

    //O(1)
    T pop() {
        if(isEmpty()) {
            cout << "stack is empty" << endl;
            return 0;
        }
        Node<T> *temp = head;
        head = head -> next;

        T toPop = temp -> data;
        delete temp;

        length--;

        return toPop;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int size() {
        return length;
    }
};
