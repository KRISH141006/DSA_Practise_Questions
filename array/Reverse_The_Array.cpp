/*
Basically there are main 4 methods of reversing the array
1. using a temp vector with same size
    -first copy all the elements in reverse from array to temp array
    -then paste all the elements from temp array to array
2. using left right pointer
    -pick 2 pointer positions 1 - left = 0 , 2 - right = arr.size()-1
    -while(left<right){
        swap(array[left],array[right]);
        left++;
        right--;
    }
3. swap elements
    -run for loop for half of the array 
    -swap(array[i],array[size-i-1]);
4. using reverse function
    -reverse(arr.begin(),arr.end());
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
    void reverseArray(vector<int> &arr) {
        for(int i=0;i<arr.size()/2;i++){
            swap(arr[i],arr[arr.size()-i-1]);
        }
    }
};
int main(){
    Solution s;
    vector<int> arr = {1,3,5,6,8,4,2,5};
    cout<<"Before : ";
    printArray(arr);
    s.reverseArray(arr);
    cout<<"After : ";
    printArray(arr);
    return 0;
}