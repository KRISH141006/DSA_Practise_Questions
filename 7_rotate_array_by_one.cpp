#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution {
  public:
    void rotate(vector<int> &arr) {
       int last = arr[arr.size() - 1];
       for(int i = arr.size()-1;i>0;i--){
           arr[i] = arr[i-1];
       }
       arr[0] = last;
        
    }
};
int main(){
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    s.rotate(arr);
    printContainer(arr);
    return 0;
}