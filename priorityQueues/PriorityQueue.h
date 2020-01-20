#include <vector>

class PriorityQueue {
	vector<int> pq;

	PriorityQueue() {
	}

	bool isEmpty() {
		return pq.size() == 0;
	}


	// returns the size of priorityQueue.
	int getSize() {
		return pq.size();
	}

	// returns elemeent with minimum priority.
	int getMin() {
		if(isEmpty()) {
			return -1;
		}
		return pq[0];
	}

	void insert(int element) {
		pq.push_back(element);

		int childIndex = pq.size()-1;

		

		while(childIndex > 0) {
			int parentIndex = (childIndex - 1) /2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[parentIndex] = pq[childIndex];
				pq[childIndex] = temp;
			}
			else {
				break;
			}
			childIndex = parentIndex;
		}
	}

	int removeMin() {
		if(isEmpty()) {
			return 0;
		}

		int ans = pq[0];
		pq[0] = pq[pq.size()-1];
		pq.pop_back();

		int parentIndex = 0;
		int lChildIndex = 2*parentIndex + 1;
		int rChildIndex = 2*parentIndex + 2;

		while(lChildIndex < pq.size()) {
			int minIndex = parentIndex;
			if(pq[minIndex] > pq[lChildIndex]) {
				minIndex = lChildIndex;
			}
			if(rChildIndex < pq.size() && pq[minIndex] > pq[rChildIndex]){
				minIndex = rChildIndex;
			}
			if(minIndex == parentIndex) {
				break;
			}

			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			lChildIndex = 2*parentIndex + 1;
			rChildIndex = 2*parentIndex + 2;
		}
		return ans;
	}

	void inplaceHeapSort(int input[], int n) {
		for(int i = 0; i < n; i++) {

			int childIndex = i;
			while(childIndex > 0) {
				int parentIndex = (childIndex-1)/2;
				if(input[childIndex] < input[parentIndex]) {
					int temp = input[childIndex];
					input[childIndex] = input[parentIndex];
					input[parentIndex] = temp;
				} else {
					break;
				}
				childIndex = parentIndex;
			}
		}
	}
};