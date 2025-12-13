#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    if (op == '^') return pow(a, b);
    return 0;
}

string infixToPostfix(string s) {
    stack<char> st;
    string postfix;

    for (char c : s) {
        if (isdigit(c)) {
            postfix += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int evaluatePostfix(string s) {
    stack<int> st;

    for (char c : s) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(applyOp(a, b, c));
        }
    }
    return st.top();
}

int main() {
    string infix = "(2+4)*(4+6)";
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
