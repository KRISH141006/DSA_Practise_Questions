#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int floorDiv(int a, int b) {
        if (a % b == 0) return a / b;
        if ((a < 0) ^ (b < 0)) return (a / b) - 1;
        return a / b;
    }

    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        
        for (string s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(floorDiv(a, b));
                else if (s == "^") st.push(pow(a, b));
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

int main() {
    Solution s;
    vector<string> arr = {"-8", "3", "/"};
    cout << s.evaluatePostfix(arr); // Output: -3
    return 0;
}
