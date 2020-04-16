/*Harshit gave Aahad an array of size N and asked to minimize the difference between
the maximum value and minimum value by modifying the array under the condition
that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help.

sample in -
3 6
1 15 10

sample out-
5
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long* arr = new long[n];
    for(long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    long small = arr[0] + k;
    long big = arr[n-1] - k;
    if(small > big) {
        long temp = small;
        small = big;
        big = temp;
    }

    for(long i = 1; i < n-1; i++) {
        long sub = arr[i] - k;
        long add = arr[i] + k;
        if((sub >= small) || (add <= big)) {
            continue;
        }
        else if((big - sub) <= (add - sub)) {
            small = sub;
        }
        else {
            big = add;
        }
    }

    long ans = min(arr[n-1]-arr[0], big-small);
    cout << ans << endl;
    delete []arr;
    return 0;
}
