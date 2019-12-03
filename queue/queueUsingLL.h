template <typename T>
class Node {
    Node<T> *next;
    T data;

    public :

    Node(T data) {
        this -> data = data;
        this -> next = NULL;
    }
};

template <typename T>
class Queue {
    Node<T> *entry;
    Node<T> *exit;  // exit pointer corresponds to head node.
    int length;

    public :

    Queue() {
        entry = NULL;
        exit = NULL;
        length = 0;
    }

    int getSize() {
        return length;
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void enqueue(T data) {
        Node<T> *newnode = new Node<T>(data);
        if(exit == NULL) {
            exit = newnode;
        }
        else {
            entry -> next = newnode;
        }
        entry = newnode;
        length++;
    }

    T dequeue() {
        if(isEmpty()) {
            std :: cout << "Queue is empty!" << std :: endl;
            return 0;
        }
        Node<T> *temp = exit;
        exit = exit -> next;
        T dataToReturn = temp -> data;
        delete temp;
        length--;
        if(length == 0) {
            entry = NULL;
        }
        return dataToReturn;
    }

    T front() {
        if(isEmpty()) {
            std :: cout << "Queue is empty!" << std :: endl;
            return 0;
        }
        return exit -> data;
    }

};
