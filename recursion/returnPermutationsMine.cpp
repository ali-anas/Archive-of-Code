#include <iostream>
#include <string>

using namespace std;

int permutations(string input, string output[], int index)
{
    if(input.length() == 1)
    {
        output[index] = input[0];
        return 1;
    }
    int myAns = 0;
    for(int i = 0; i < input.length(); i++)
    {
        char toInsert = input[i];
        string smallInput = input.substr(0,i) + input.substr(i+1);
        int smallAns = permutations(smallInput, output, index);
        myAns += smallAns;

        for(int j = 0; j < smallAns; j++)
        {
            output[j+index] = toInsert + output[j+index];
        }
        index += smallAns;
    }
    return myAns;
}


int main()
{
    string input;
    cin >> input;
    string output[10000];
    int index = 0;
    int noOfPermutations = permutations(input, output, index);
    for(int i = 0; i < noOfPermutations && i < 10000; i++)
    {
        cout << output[i] << "\n";
    }
    cout << noOfPermutations << endl;
    return 0;
}
