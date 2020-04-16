 
#include <bits/stdc++.h>
using namespace std;

map<int,int> returnPrimeFactors(int k)
{
    map<int,int> primeFactors;
    while(k % 2 == 0)
    {
        primeFactors[2]++;
        k /=2 ;
    }

    for(int i = 3; i <= sqrt(k) ; i++)
    {
        while(k % i == 0)
        {
            primeFactors[i]++;
            k /= i;
        } 
    }

    if(k > 2)
        primeFactors[k]++;
    
    return primeFactors;
}


long long solve(vector<int> arr,int n,int k)
{
    map<int,int> primeFactorsK = returnPrimeFactors(k);
    map<int,int> primeFactorsA;
    vector<bool> visited(n);

    int i=0,j=0,s=0;
    int ans = 0;
    while(i<n && j<n)
    {
    	
        int flag = 0;
        for(auto it:primeFactorsK)
        {
            int p = it.first;
            int count = 0;
            int val = arr[j];
            while(val % p == 0)
            {
                count++;
                val /= p;
            }
            if(!visited[j])
                primeFactorsA[p] += count;
            if(primeFactorsA[p] < it.second)
            {
                flag = 1;
            }
        }

        if(!flag)
        {
            ans += (n-j);
            s = i;
            visited[j] = true;
            i++;
            int m = i-1;
            while(m >= s)
            {
                int flag = 0;
                for(auto it:primeFactorsK)
                {
                    int p = it.first;
                    int count = 0;
                    int val = arr[m];
                    while(val % p == 0)
                    {
                        count++;
                        val /= p;
                    }
                    primeFactorsA[p] -= count;
                    if(primeFactorsA[p] < it.second)
                    {
                        flag = 1;
                    }
                }
                if(flag)
                    break;
                m--;
            }
        }
        else
            j++;
    }
    return ans;
}

int main()
{
    int n,k,i,j;
    cin >> n >> k;

    vector<int> arr(n);
    for(i = 0; i < n ; i++) {
        cin >> arr[i];
    }

    solve(arr,n,k)<<endl;

}
