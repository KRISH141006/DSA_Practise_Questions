#include<bits/stdc++.h>
using namespace std;

stack<int> minS;

void push(stack<int>& s, int a) {
    s.push(a);
    if (minS.empty() || a <= minS.top())
        minS.push(a);
}

bool isFull(stack<int>& s, int n) {
    return s.size() == n;
}

bool isEmpty(stack<int>& s) {
    return s.empty();
}

int pop(stack<int>& s) {
    if (s.empty()) return -1;
    
    int x = s.top();
    s.pop();
    
    if (!minS.empty() && x == minS.top())
        minS.pop();
    
    return x;
}

int getMin(stack<int>& s) {
    if (minS.empty()) return -1;
    return minS.top();
}

int main() {
    stack<int> s;
    int n = 5;

    push(s, 18);
    push(s, 19);
    push(s, 29);
    push(s, 15);
    push(s, 16);

    cout << getMin(s) << endl;  // Output: 15

    pop(s);
    cout << getMin(s) << endl;  // Output: 15

    return 0;
}
