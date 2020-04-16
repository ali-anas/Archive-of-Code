/*
    Harshit knows by his resources that this time the winning lottery number is
    the smallest number whose sum of the digits is S and the number of digits
    is D. You have to help Harshit and print the winning lottery number.

    input- S,D

    1 <= D <= 1000
    1 <= S <= 9*D
    Time Limit: 1 second

    sample input:
    9 2
    sample output:
    18
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int D,S;
    cin >> S >> D;
    int* arr = new int[D];
    arr[0] = 1;

    int to_fill = S-1;
    for(int i = D-1; i > 0; i--) {
        if(to_fill >= 9) {
            arr[i] = 9;
            to_fill -= 9;
        } else if(to_fill > 0){
            arr[i] = to_fill;
            to_fill = 0;
        } else {
            arr[i] = to_fill;
        }
    }
    if(to_fill > 0) {
        arr[0] += to_fill;
    }

    string ans = "";
    for(int i = 0; i < D; i++) {
        ans += char(48+arr[i]);
    }
    delete []arr;
    cout << ans << endl;
    return 0;
}
