#include <bits/stdc++.h>
using namespace std;

stack<char> st;

void insert_at_bottom(char x) {
    if (st.empty()) {
        st.push(x);
        return;   // optional, but clear
    }

    char a = st.top();
    st.pop();
    insert_at_bottom(x);
    st.push(a);
}

int main() {
    st.push('A');
    st.push('B');
    st.push('C');

    insert_at_bottom('X');

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
