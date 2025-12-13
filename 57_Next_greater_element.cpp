#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i])
                st.pop();
            
            if (!st.empty())
                ans[i] = st.top();
            
            st.push(arr[i]);
        }
        return ans;
    }
};

void printVector(vector<int>& v) {
    for (int x : v) cout << x << " ";
    cout << endl;
}

int main() {
    Solution s;
    vector<int> arr = {1, 3, 2, 4};
    
    vector<int> res = s.nextLargerElement(arr);
    printVector(res);   // Output: 3 4 4 -1
    
    return 0;
}
