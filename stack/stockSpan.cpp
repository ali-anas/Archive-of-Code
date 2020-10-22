#include <stack>


int* stockSpan(int *price, int size) {
	// Write your code here
    int* span = new int[size];
    stack<int> s;
    span[0] = 1;
    s.push(0);
    
    int i = 1;
    while(i < size) {
        if(price[i] <= price[i-1]) {
            span[i] = i - s.top();
            s.push(i);
        }
        else {
            while(!s.empty() && (price[i] > price[s.top()])) {
                s.pop();
            }
            if(s.empty()) {
                span[i] = i + 1;
                
            }
            else {
                span[i] = i - s.top();
            }
            s.push(i);
        }
        i++;
    }
    return span;    
}
