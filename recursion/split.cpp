#include <iostream>
// #include "solution.h"
using namespace std;

bool getsum(int input[], int size, int start, int sum5, int sum3) {
    if(start == size) {
        return sum5 == sum3;
    }

    if(input[start] % 5 == 0) {
        sum5 += input[start];
    }
    else if(input[start] % 3 == 0) {
        sum3 += input[start];
    }
    else   // adding to both one by one.
        return getsum(input, size, start+1, sum5 + input[start], sum3) || getsum(input, size, start+1, sum5, sum3+input[start]);

    return getsum(input, size, start+1, sum5, sum3);
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return getsum(input, size, 0, 0, 0);
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }


	return 0;

}
