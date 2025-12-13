#include<bits/stdc++.h>
using namespace std;

class twoStacks {
public:
    int *arr;
    int top1, top2;
    int size;
    
    twoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if (top1 < top2 - 1)
            arr[++top1] = x;
    }

    void push2(int x) {
        if (top1 < top2 - 1)
            arr[--top2] = x;
    }

    int pop1() {
        if (top1 >= 0)
            return arr[top1--];
        return -1;
    }

    int pop2() {
        if (top2 < size)
            return arr[top2++];
        return -1;
    }
};

int main() {
    twoStacks ts(10);

    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    cout << ts.pop1() << endl; // 20
    cout << ts.pop2() << endl; // 40

    return 0;
}
