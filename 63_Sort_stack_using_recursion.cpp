#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertSorted(stack<int>& st, int x) {
        if (st.empty() || st.top() <= x) {
            st.push(x);
            return;
        }
        
        int temp = st.top();
        st.pop();
        insertSorted(st, x);
        st.push(temp);
    }
    
    void sortStack(stack<int>& st) {
        if (st.empty()) return;
        
        int x = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, x);
    }
};

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(41);
    st.push(3);
    st.push(32);
    st.push(2);
    st.push(11);

    Solution s;
    s.sortStack(st);

    printStack(st);   // Output: 41 32 11 3 2
    return 0;
}
