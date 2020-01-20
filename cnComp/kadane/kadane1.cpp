/* 
 * gives maximum sum that a 
 * subarray can have in given
 * array
*/

#include <iostream>

using namespace std;

/*
 * uses kadane's algorithm.
*/
int maxSumSubarray(int *arr, int n) {
    int curr_sum = 0;
    int best_sum = 0;
    for(int i = 0; i < n; i++) {
        curr_sum += arr[i];
        if(best_sum < curr_sum) {
            best_sum = curr_sum;
            
        }
        // if baggage is found -> negative integers.
        else {
            curr_sum = 0;
        }
    }
    return best_sum;
}

int main() {
    cout << "enter number of elements : ";
    int n;
    cin >> n;
    int *array = new int[n];
    cout << "\n enter elements : ";
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "\n" << maxSumSubarray(array, n) << endl;
    return 0;
}