#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int a = 0, b = n - 1;
        
        while (a < b) {
            if (mat[a][b] == 1)
                a++;
            else
                b--;
        }
        
        int cand = a;
        
        for (int i = 0; i < n; i++) {
            if (i != cand) {
                if (mat[cand][i] == 1 || mat[i][cand] == 0)
                    return -1;
            }
        }
        return cand;
    }
};

int main() {
    Solution s;
    
    vector<vector<int>> mat = {
        {1, 1, 0},
        {0, 1, 0},
        {0, 1, 1}
    };
    
    cout << s.celebrity(mat);  // Output: 1
    return 0;
}

