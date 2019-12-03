#include <iostream>



void merge(int input[], int start,int mid, int end)
{
    int arr[end-start+1];
    //int size1 = mid -start + 1;
    //int size2 = end-mid;
    int k = 0, i = start, j = mid+1;
    for(int p = start; p <= end; p++)
    {
        if(i > mid)
            arr[k++] = input[j++];
        else if(j > end)
            arr[k++] = input[i++];
        else if(input[i] < input[j])
            arr[k++] = input[i++];
        else
            arr[k++] = input[j++];
    }
    for(int i = 0; i < k; i++)
    {
        input[start++] = arr[i];
    }
}

void mergesort(int input[], int start, int end)
{
    //std::cout << "start : " << start << " end : " << end << std::endl;
    if(start >= end)
        return ;
    int mid = (start+end)/2;
    //std::cout << " mid : "<< mid << std::endl;
    mergesort(input, start, mid);

    mergesort(input, mid+1, end);
    merge(input, start, mid, end);
    //return ;
}
