#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& arr){
    for(int x : arr) cout << x << " ";
    cout << endl;
}

class Solution {
public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        int low = 0, mid = 0, high = arr.size() - 1;
        
        while (mid <= high) {
            if (arr[mid] < a) {
                swap(arr[low++], arr[mid++]);
            } 
            else if (arr[mid] > b) {
                swap(arr[mid], arr[high--]);
            } 
            else {
                mid++;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 4, 3, 6, 2, 1};
    int a = 1, b = 3;
    s.threeWayPartition(arr, a, b);
    printVector(arr);
    return 0;
}
