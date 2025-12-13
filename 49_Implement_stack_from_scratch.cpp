#include<bits/stdc++.h>
using namespace std;

class MyStack {
private:
    int maxSize;
    long *stackArray;
    int top;

public:
    MyStack(int s) {
        maxSize = s;
        stackArray = new long[maxSize];
        top = -1;
    }

    void push(long x) {
        stackArray[++top] = x;
    }

    long pop() {
        return stackArray[top--];
    }

    long peek() {
        return stackArray[top];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == maxSize - 1);
    }
};

int main() {
    MyStack theStack(10);

    theStack.push(10);
    theStack.push(20);
    theStack.push(30);
    theStack.push(40);
    theStack.push(50);

    while (!theStack.isEmpty()) {
        cout << theStack.pop() << " ";
    }
    cout << endl;

    return 0;
}
