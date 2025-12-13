#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> mat){
        vector<int> list;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                list.push_back(mat[i][j]);
                // cout<<mat[i][j]<<" ";

            }
            // cout<<endl;
        }
        // for(int i : list){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        sort(list.begin(),list.end());
        int k =0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                mat[i][j] = list[k++];
            }
        }

        return mat;
    }
};
int main(){
    Solution s;
    int N = 4;
    vector<vector<int>> mat = {{10,20,30,40},{15,25,35,45},{27,29,37,48}, {32,33,39,50}};
    mat = s.sortedMatrix(N,mat);
    for(int i=0;i<mat.size();i++){
        printContainer(mat[i]);
    }
    return 0;
}
