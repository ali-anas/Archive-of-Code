#include<bits/stdc++.h>
using namespace std;

struct job {
    int start;
    int finish;
    int profit;
};

bool compare(job job1, job job2) {
    return job1.finish < job2.finish;
}

int getByIncluding(struct job* input, int curr, int* dp) {
    int including = input[curr].profit;
    int start = 0;
    int end = curr-1;
    int best = -1;
    while(start <= end) {
        int mid = start + (end-start) / 2;
        if(input[mid].finish <= input[curr].start) {
            best = mid;
            start = mid+1;
        } else {
            end = mid - 1;
        }
    }
    
    if(best == -1) {
        return including;
    }
    including += dp[best];
    return including;
}

int getProfit(struct job* input, const int &n) {
    sort(input, input+n, compare);
    int dp[n];
    dp[0] = input[0].profit;
    
    for(int i = 1; i < n; i++) {
        int including = getByIncluding(input, i, dp);
        
        
        dp[i] = max(dp[i-1], including);
    }
    return dp[n-1];
}

int main()
{
    //Write your code here
    int n;
    scanf("%d", &n);
    job* input = new job[n];
    for(int i = 0; i < n; i++) {
        int s,f,p;
        scanf("%d%d%d", &s, &f, &p);
        input[i].start = s;
        input[i].finish = f;
        input[i].profit = p;
    }
    
    int maxProfit = getProfit(input, n);
    printf("%d\n", maxProfit);
    return 0;
}
