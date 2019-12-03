#include <iostream>

using namespace std;

int subSet(int input[], int n, int output[][20])
{
    if(n == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    int smallAns = subSet(input+1, n-1, output);
    
    for(int i = 0; i < 2*smallAns; i++)
    {
        output[i+smallAns][0] = output[i][0] + 1;
        output[i+smallAns][1] = input[0];
        int range = output[i][0];
        for(int j = 1; j <= range; j++)
        {
            output[i+smallAns][j+1] = output[i][j];
        }
    }
    /*
    for(int i = 0; i < 2 * smallAns; i++)
    {
        output[i+smallAns][0] = output[i][0] + 1;
        int j = output[i+smallAns][0];
        for(; j>1; j--)
        {
            output[i + smallAns][j] = output[i][j-1];
        }
        output[i+smallAns][j] = input[0];
    }*/
    return 2*smallAns;
}

int main()
{
    int n;
    cin >> n;
    int input[n];
    int output[10000][20];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int ans = subSet(input, n, output);
    for(int i = 0; i < ans; i++)
    {
        int indexRange = output[i][0];
        for(int j = 0; j <= indexRange; j++)
        {
            cout << output[i][j];
        }
        cout << "\n";
    }
    return 0;
}
