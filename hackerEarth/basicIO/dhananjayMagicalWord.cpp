#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int getIndex(char ch, int primeAscii[])
{
    int index = ch;
    if(index < 65)
    {
        //int minus = index - 48;
        index = 65;
    }
    if(primeAscii[index] == 1)
    {
        return index;
    }
    int left = index, right = index;
    while(primeAscii[left] != 1)
    {
        left--;
    }
    while(primeAscii[right] != 1)
    {
        right++;
    }
    if((right > 122) || (right > 90 && right < 97))
    {
        return left;
    }
    if((left < 65) || (left > 90 && left < 97))
    {
        return right;
    }
    //if (int(ch) >= 48 && int(ch) <= 57 && right > 57)
    //{
    //    return left;
    //}
    //if (int(ch) >= 48 && int(ch) <= 57 && left < 48)
    //{
    //    return right;
    //}
    int rightDistance = right - index;
    int leftDistance = index - left;
    if(leftDistance == rightDistance)
    {
        return left;
    }
    else if(leftDistance < rightDistance)
    {
        return left;
    }
    else
        return right;
    return index;
}

int main()
{
    int testCases;
    cin >> testCases;
    int primeAscii[257];
    for(int i = 0; i <= 256; i++)
    {
        if(isPrime(i))
        {
            primeAscii[i] = 1;
        }
        else
        {
            primeAscii[i] = 0;
        }
    }
    for(int i = 48; i <= 130; i++)
    {
        cout << i << " " << primeAscii[i] << " " << char(i) << endl;
    }
    while(testCases > 0)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        for(int i = 0; i < n; i++)
        {
           int changedIndex = getIndex(s[i], primeAscii);
           //cout << "changedIndex" << changedIndex ;
           s[i] = char(changedIndex);
           //cout << "\t" << s << endl;
        }
        cout << s << "\n";
        testCases--;
    }
    return 0;
}
