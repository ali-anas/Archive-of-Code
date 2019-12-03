template <typename T>
class Queue {
    T *data;
    int entryPoint;
    int exitPoint;
    int size;
    int capacity;

    public :

    Queue(int s) {
        data = new T[s];
        this -> entryPoint = 0;
        this -> exitPoint = -1;
        this -> size = 0;
        this -> capacity = s;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    // insert an element.
    void enqueue(T element) {
        if(size == capacity) {
            T *newdata = new T[2*capacity];
            int j = 0;
            for(int i = exitPoint; i < capacity; i++) {
                newdata[j] = data[i];
                j++;
            }
            for(int i = 0; i < entryPoint; i++) {
                newdata[j] = data[i];
                j++;
            }
            delete [] data;
            data = newdata;
            exitPoint = 0;
            entryPoint = capacity;
            capacity *= 2;
        }
        data[entryPoint] = element;
        entryPoint = (entryPoint + 1) % capacity;
        if(exitPoint == -1) {
            exitPoint = 0;
        }
        size++;
    }

    // return front.
    T front() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return 0;
        }
        return data[exitPoint];
    }

    // rempve an element.
    T dequeue() {
        if(isEmpty()) {
            cout << "Queue is empty!";
            return 0;
        }
        T ans = data[exitPoint];
        exitPoint = (exitPoint+1) % capacity;
        size--;
        if(size == 0) {
            entryPoint = 0;
            exitPoint = -1;
        }
        return ans;
    }
};
