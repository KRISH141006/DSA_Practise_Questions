#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find3Numbers(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == target) return true;
                else if (sum < target) l++;
                else r--;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 13;
    cout << s.find3Numbers(arr, target);
    return 0;
}
