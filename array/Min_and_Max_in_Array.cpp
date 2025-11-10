/*
So there are 4 ways to solve this question
1. Sort the array and return 0th element and last element
2. iterate all the array and compare all the elements
    minVal = min(minVal,arr[i]) , maxVal = max(maxVal,arr[i])
3. using function - min_element(arr.begin(),arr.end())
                  - max_element(arr.begin(),arr.end())
*/
#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr){
    for(int x : arr)
        cout<<x<<" ";
    cout<<endl;
}

class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int mini=arr[0],maxi=arr[0];
        for(int x : arr){
            mini = min(x,mini);
            maxi = max(x,maxi);
        }
        return {mini,maxi};
    }
};

int main(){
    Solution s;

    vector<int> arr = {1,3,5,6,8,4,2,5};
    vector<int> minMax = s.getMinMax(arr);
    cout<<"min , max : ";
    cout<<minMax[0]<<" , "<<minMax[1];
    return 0;
}
