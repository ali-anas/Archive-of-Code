#include <stack>
#include <iostream>

using namespace std;

void reverse(stack<int> &in, stack<int> &ex) {
     if(in.empty()) {
        return;
    }
    int element = in.top();
    in.pop();
    reverse(in, ex);
    ex.push(element);
    return;
}

void reverseStack(stack<int> &input, stack<int> &extra) {
    reverse(input, extra);
    while(!extra.empty()) {
        int element = extra.top();
        extra.pop();
        input.push(element);
    }
   return;
}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
