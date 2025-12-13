#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    int median(vector<vector<int>> &mat){
        vector<int> list;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                list.push_back(mat[i][j]);

            }
        }
        sort(list.begin(),list.end());
        
        int n = list.size();
        return list[n / 2];  
    }
};
int main(){
    Solution s;
    vector<vector<int>> mat = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    cout<<s.median(mat);
    return 0;
}