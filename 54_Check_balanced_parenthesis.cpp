#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ispar(string x) {
        stack<char> st;
        
        for (char c : x) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                
                char t = st.top();
                st.pop();
                
                if ((c == ')' && t != '(') ||
                    (c == '}' && t != '{') ||
                    (c == ']' && t != '['))
                    return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    string str = "[{()}]";
    cout << s.ispar(str);
    return 0;
}
