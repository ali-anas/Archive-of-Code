#include <iostream>
#include <string>

using namespace std;

int returnPermutations(string input, string output[])
{
    if(input.length() == 0)
    {
        output[0] = "";
        return 1;
    }
    string smallOutput[10000];
    int smallAns = returnPermutations(input.substr(1), smallOutput);

    int k = 0;
    for(int i = 0; i < smallAns; i++)
    {
        for(int j = 0; j <= smallOutput[i].length(); j++)
        {
            output[k++] = smallOutput[i].substr(0,j) + input[0] + smallOutput[i].substr(j);
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int noOfPermutations = returnPermutations(input, output);
    for(int i = 0; i < noOfPermutations && i < 10000; i++)
    {
        cout << output[i] << "\n";
    }
    cout << noOfPermutations << endl;
    return 0;
}
