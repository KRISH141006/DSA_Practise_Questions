#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxHist(vector<int>& hist) {
        stack<int> st;
        int maxA = 0, i = 0, n = hist.size();
        
        while (i < n) {
            if (st.empty() || hist[st.top()] <= hist[i]) {
                st.push(i++);
            } else {
                int tp = st.top(); st.pop();
                int area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
                maxA = max(maxA, area);
            }
        }
        
        while (!st.empty()) {
            int tp = st.top(); st.pop();
            int area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
            maxA = max(maxA, area);
        }
        return maxA;
    }
    
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> hist(m, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hist[j] = (mat[i][j] == 0) ? 0 : hist[j] + 1;
            }
            ans = max(ans, maxHist(hist));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {
        {0,1,1,0},
        {1,1,1,1},
        {1,1,1,1},
        {1,1,0,0}
    };
    cout << s.maxArea(mat);
    return 0;
}
