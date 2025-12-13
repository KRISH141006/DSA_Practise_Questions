#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(mat[i][j]);
            }
        }
        
        while (--k) pq.pop();
        return pq.top();
    }
};

int main(){
    Solution s;
    vector<vector<int>> mat = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };
    int k = 3;
    cout << s.kthSmallest(mat, k);
    return 0;
}
