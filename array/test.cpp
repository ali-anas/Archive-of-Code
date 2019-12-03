// FIND WORD OF MINIMUM LENGTH IN A GIVEN CHARACTER ARRAY.

#include <iostream>

using namespace std;

void minLengthWord(char input[], char output[]){

	// Write your code here
    int startaddress[100000];
    int count[1000000];

    startaddress[0] = 0;

    int startindex = 1;
    int countindex = 0;

    int i = 0;
    int j = 0;
    while(input[i] != '\0')
    {
        while(input[j] != ' ' || input[j] != '\0')
        {
            j++;
        }
        count[countindex] =  j - startaddress[countindex];
        countindex++;
        startaddress[startindex] = j+1;
        startindex++;
        i = j;
        j++;
    }
    int min = count[0];
    int index  = 0;
    for(int k = 0; k < countindex; k++)
    {
        cout << count[k];
    }
    for(int k = 0; k < startindex; k++)
    {
        cout << startaddress[k];
    }
    for(i = 1; i < countindex; i++)
    {
        if(count[i] < min)
        {
            min = count[i];
            index = i;
        }
    }

    for(i = 0; i < min; i++)
    {
        output[i] = input[index+i];
    }

}

int main()
{
    char input[100], output[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    minLengthWord(input, output);
    int j = 0;
    while(output[j]!='\0')
    {
        j++;
    }
    for(int i = 0; i < j; j++)
    {
        cout << output[i];
    }
    return 0;
}
