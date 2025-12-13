#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    int rowWithMax1s(vector<vector<int>> &arr){
        int maxn=INT_MIN,index=0;
         for(int i=0;i<arr.size();i++){
            int count = 0;
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j] == 1) count++;
            }
            if(count>maxn){
                maxn = count;
                index = i;
            }
        }
        return index;
    }
};
int main(){
    Solution s;
    vector<vector<int>> arr = {{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};
    cout<<s.rowWithMax1s(arr);
    return 0;
}