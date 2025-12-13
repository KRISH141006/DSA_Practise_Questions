#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getMaxArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long maxArea = 0;
        int i = 0;
        
        while (i < n) {
            if (st.empty() || arr[st.top()] <= arr[i]) {
                st.push(i++);
            } else {
                int tp = st.top();
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, (long long)arr[tp] * width);
            }
        }
        
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
            long long width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, (long long)arr[tp] * width);
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> arr = {60, 20, 50, 40, 10, 50, 60};
    cout << s.getMaxArea(arr);   // Output: 100
    return 0;
}

