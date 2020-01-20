/* for each element at index i
 * prod[i] will be prod of all
 * other elements present in array
 * except element at index i.
 * constrain - don't use '/' operator.
 * and space complexity
 * should be constant.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        long prod[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }


        long left_prod_ele = 1;
        for(int i = 0; i < n; i++) {
            prod[i] = left_prod_ele;
            left_prod_ele *= arr[i];
        }

        long right_prod_ele = 1;
        for(int i = n-1; i >= 0; i--) {
            prod[i] *= right_prod_ele;
            right_prod_ele *= arr[i];
        }

        for(int i = 0; i < n; i++) {
            cout << prod[i] << " ";
        }
    }
    return 0;
}