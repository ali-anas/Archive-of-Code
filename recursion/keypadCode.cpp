#include <iostream>
#include <cmath>

using namespace std;



int findsubSequences(int n, string output[],string sequence[])
{
    if(n == 0)
    {
        output[0] = "";
        return 1;
    }
    //string smallString = input.substr(1);
    int rem = (n%10);

    int smallAns = findsubSequences(n/10, output, sequence);

    string option = sequence[rem];
    int length = option.length();
    int k = 0;

    // first copy the previous output length times in output
    for(int currlength = 0; currlength < length; currlength++)
    {
        for(int prevlength = 0; prevlength < smallAns; prevlength++)
        {
            //int index = prevlength+(currlength*smallAns);
            //cout << index << endl;
            output[k] = output[prevlength];
            k++;
        }
    }
    k = 0;
    // concatenate elements of current string
    for(int currlength = 0; currlength < length; currlength++)
    {
        for(int prevlength = 0; prevlength < smallAns; prevlength++)
        {
            output[k] += option[currlength];
            k++;
        }
    }

    return k;
}

int main()
{
    string sequence[] = {"" ,"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n;
    int outputSize = 1;
    cin >> n;
    int number_copy = n;
    while(n > 0)
    {
        int rem = n % 10;
        if(rem >= 2 && rem <= 9)
        {
            outputSize  = outputSize * sequence[rem].size();
        }
        n = n/10;
    }
    string* output = new string[outputSize];
    int count = findsubSequences(number_copy, output, sequence);
    for(int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    cout <<"outputsize : " << outputSize << endl;
    cout <<"total : " << count << endl;
    /*for(int i = 0; i < 8; i++)
    {
        delete []sequence[i];
    }*/
    //delete []sequence;
    /*for(int i = 0; i < outputSize; i++)
    {
        delete []output[i];
    }*/
    delete []output;
    return 0;
}
