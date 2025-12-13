// 22 Search element in matrix
#include <bits/stdc++.h>
using namespace std;

int main() {
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0, high = m * n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = matrix[mid / n][mid % n];
            
            if (val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int target = 3;
    cout << s.searchMatrix(matrix, target);
    return 0;
}
