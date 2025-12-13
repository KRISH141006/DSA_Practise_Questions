#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
int maxSubarraySum(vector<int> &arr){
    
        int maxSum = INT_MIN,currSum = 0;
        
        for(int elms : arr){
            currSum += elms;
            maxSum = max(currSum,maxSum);
            
            if(currSum<0) currSum = 0;
        }
        
        return maxSum;
    }
};
int main(){
    Solution s;
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    cout<<s.maxSubarraySum(arr);
    return 0;
}