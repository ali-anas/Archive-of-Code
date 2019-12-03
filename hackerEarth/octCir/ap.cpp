#include <bits/stdc++.h>

using namespace std;

int findLength(int *myarr, int l, int r, int d, int count)
{
    //int count = 0;
    int count1 = 0;
    int start = l;
    while(start < r)
    {
        //if(myarr[start+2] + myarr[start] == 2 * d)
        //{
        //    count1 += 3;
        //    start += 3;
        //}
        if(myarr[start+1] - myarr[start] == d)
        {
            count1 += 2;
            start += 2;
        }
        else if(myarr[start] - myarr[start-1] == d)
        {
            count1 += 1;
            start += 1;
        }
        else
        {
            count = max(count, count1);
            count1 = 0;
            start++;
        }
        //l++;
    }
    count = max(count, count1);
    return count;
}

int main()
{
    int n , q;
    cin >> n >> q;
    int *myarr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> myarr[i];
    }
    while(q > 0)
    {
        int l, r, d;
        cin >> l >> r >> d;
        int length = 1;
        if(r-l > 0)
        {
            length = findLength(myarr, l-1, r-1, d, length);
        }
        //if(r-l == 0)
        //    length = 1;
        cout << length << "\n";
        q--;
    }
    return 0;
}
