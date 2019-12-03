template <typename T>
class stack {
	private :
		int next;
		T *arr;
		int stacksize;
	public :
		stack() {
			this -> arr = new T[5];
			this -> next = 0;
			this -> stacksize = 5;
		}

		int size() {
			return next;
		}

		bool isEmpty() {
			return next == 0;
		}

		//insert element.
		void push(T element) {
			if(next == stacksize) {
				T *newarr = new T[2*stacksize];
				for(int i = 0; i < stacksize; i++ )
				{
					newarr[i] = arr[i];
				}
				stacksize *= 2;
				delete []arr;
				arr = newarr;
			}
			arr[next] = element;
			next++;
		}

		T pop() {
			if(isEmpty()) {
				std :: cout << "Stack is empty!" << std :: endl;
				return 0;
			}
			next--;
			return arr[next];
		}

		T top() {
			if(isEmpty()) {
				std :: cout << "Stack is empty!" << std :: endl;
				return 0;
			}
			return arr[next-1];
		}
};
