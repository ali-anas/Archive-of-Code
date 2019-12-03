#include <iostream>

using namespace std;

void leaders(int *arr, int len)
{
    int maximum = arr[len-1];
    //cout << maximum << endl;
    int ans[1000000];
    int n = 0;
    for(int i = len-1; i >= 0; i--)
    {
        if(arr[i] >= maximum)
        {
            ans[n++] = arr[i];
            maximum = arr[i];
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return;
}

int main()
{
    int arr[1000000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    leaders(arr, n);
    return 0;
}
