#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool matches(char tocheck, char top) {
    if(top == '{' && tocheck == '}') {
        return true;
    }
    if(top == '(' && tocheck == ')') {
        return true;
    }
    if(top == '[' && tocheck == ']') {
        return true;
    }
    return false;
}

bool isbalanced(string const &ques) {
    stack<char> s;
    for(char ch: ques) {
        if(ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        if(ch == ')' || ch == '}' || ch == ']') {
            if(s.empty() || !(matches(ch,s.top()))) {
                return false;
            }
            else {
                s.pop();
            }
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;
}

int main() {
    string expr;
    getline(cin,expr);
    if(isbalanced(expr))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}
