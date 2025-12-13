#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    int getMinDiff(vector<int> &arr, int k){
        
        int res;
        sort(arr.begin(),arr.end());
        res = arr[arr.size()-1] - arr[0];
        
        
        for(int i = 1;i<arr.size();i++){
            if(arr[i] - k < 0) continue;
            
            int minh = min(arr[i]-k,arr[0]+k);
            int maxh = max(arr[i-1] + k,arr[arr.size()-1]-k);
            
            res = min(res,maxh-minh);
        }

        return res;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,5,8,10};
    int k = 2;
    cout<<s.getMinDiff(arr,k);
    return 0;
}