#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    vector<int> spirallyTraverse(vector<vector<int>> &mat){
        vector<int> res;
        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // left → right
            for (int c = left; c <= right; c++)
                res.push_back(mat[top][c]);
            top++;

            // top → bottom
            for (int r = top; r <= bottom; r++)
                res.push_back(mat[r][right]);
            right--;

            if (top <= bottom) {
                // right → left
                for (int c = right; c >= left; c--)
                    res.push_back(mat[bottom][c]);
                bottom--;
            }

            if (left <= right) {
                // bottom → top
                for (int r = bottom; r >= top; r--)
                    res.push_back(mat[r][left]);
                left++;
            }
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    printContainer(s.spirallyTraverse(mat));
    return 0;
}