#include <iostream>
#include <cmath>

using namespace std;

int findsubSequences(string input, string output[])
{
    if(input.size() == 0)
    {
        output[0] = "";
        return 1;
    }
    string smallString = input.substr(1);
    int smallAns = findsubSequences(smallString, output);
    for(int i = 0; i < smallAns; i++)
    {
        output[i+smallAns] = input[0] + output[i];
    }
    return 2 * smallAns;
}

int main()
{
    string input;
    cin>>input;
    int inputSize = input.size();
    int outputSize = pow(2,inputSize);
    string* output = new string[outputSize];
    int count = findsubSequences(input, output);
    for(int i = 0; i < count;i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
