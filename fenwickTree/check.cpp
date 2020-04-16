#include <bits/stdc++.h>
using namespace std;
#define MAX 1000001

int main() {
    int* arr = new int[MAX];
    //memset(arr, -1, MAX * sizeof(int));
    for(int i = 0; i < MAX; i++) {
        arr[i] = -1;
    }
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    delete []arr;
}