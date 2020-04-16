/* Perimeter with conditions-

Aahad gives an array of integers and asks Harshit to find which three elements
form a triangle (non-degenerate). The task seems easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter,
then find the one with the longest side.
3.If there are more than one combinations which satisfy all the above conditions
then find with maximum longest minimum side.

Input Format-
The First line contains no of elements of array: N
Each T lines contains N space-separated integers: A [i]

Output Format-
The output contains three space-separated elements that denote the length of the
 sides of triangle. If no such triangle is possible, then print -1.

Constraints-
1 =< N <= 10^5
1 <= A[i] <= 10^9
Time Limit: 1 second


Sample Input1:
5
1 1 1 3 3
Sample Output1:
1 3 3
Sample Input2:
3
2 2 4
Sample Output2:
-1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* input = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    #warning check the sorting order.
    sort(input, input+n, greater<int>());

    int f = 0, s= 0, t = 0;
    bool found = false;
    for(int i = 0; i < n-2; i++) {
        f = input[i];
        s = input[i+1];
        t = input[i+2];
        if(s+t > f && f+s > t && f+t > s) {
            found = true;
            break;
        }
    }
    if(found) {
        cout << t <<" "<< s << " "<< f << endl;
    }
    else {
        cout << -1 << endl;
    }

    delete []input;
    return 0;
}
