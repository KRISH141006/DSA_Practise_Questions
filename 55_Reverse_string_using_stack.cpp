#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverse(string s) {
        stack<char> st;
        for (char c : s) st.push(c);
        
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
        return s;
    }
};

int main() {
    Solution s;
    string str = "GeeksforGeeks";
    cout << s.reverse(str);
    return 0;
}
