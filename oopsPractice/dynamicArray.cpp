class DynamicArray
{
    private :
        int *data;
        int capacity;
        int nextIndex;

    public :
        DynamicArray()
        {
            this -> data = new int[5];
            this -> nextIndex = 0;
            this -> capacity = 5;
        }

        // copy constructor
        DynamicArray(DynamicArray const &obj)
        {
            this -> data = new int[obj.capacity];
            this -> capacity = obj.capacity;
            this -> nextIndex = obj.nextIndex;
            for(int i = 0; i < this -> nextIndex; i++)
            {
                this -> data[i] = obj.data[i];
            }
        }

        // overload '=' operator.
        void operator=(DynamicArray const &obj)
        {
            this -> data = new int[obj.capacity];
            this -> capacity = obj.capacity;
            this -> nextIndex = obj.nextIndex;
            for(int i = 0; i < this -> nextIndex; i++)
            {
                this -> data[i] = obj.data[i];
            }
        }

        void add(int element)
        {
            if(nextIndex == capacity)
            {
                // deep copy
                int *newData = new int[2*capacity];
                for(int i = 0; i < capacity; i++)
                {
                    newData[i] = data[i];
                }
                delete []data;
                data = newData;
                capacity *= 2;
            }
            data[nextIndex] = element;
            nextIndex++;
        }

        int get(int i) const
        {
            if(i < nextIndex)
            {
                return data[i];
            }
            else
            {
                cout << "Accessing out of bound index" << endl;
                return -1;
            }
        }

        void add(int index, int element)
        {
            if(index < nextIndex)
            {
                data[index] = element;
            }
            else if(index == nextIndex)
            {
                add(element);
            }
            else
            {
                return;
            }
        }

        void print() const
        {
            for(int i = 0; i < nextIndex; i++)
            {
                cout << data[i] << " ";
            }
            cout << "\n";
        }
};
