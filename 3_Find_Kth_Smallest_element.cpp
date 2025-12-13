#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};
// this code is for finding kth distinct smallest , i just needed to find kth smallest element ,it does not matter if it is repeating or not.READ THE QUESTION CAREFULLY YOU FOOL!!!.
// class Solution{
// public :
//     int kthSmallest(vector<int> &arr, int k){
//         if(arr.size()<2) return arr[0];
//         sort(arr.begin(),arr.end());
//         // printVector(arr);
//         int prev = arr[0];
//         int curr = arr[0];
//         k-=1;
//         for(int i = 1;i<arr.size() && k!=0;i++){
//             // cout<<"curr : "<<curr<<endl;
//             // cout<<"prev : "<<prev<<endl;
//             curr = arr[i];
//             if(curr == prev) continue;
//             prev = curr;
//             k--;
//         }
//         return curr;
//     }
// };
int main(){
    Solution s;
    vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k = 4;
    cout<<s.kthSmallest(arr,k);
    return 0;
}