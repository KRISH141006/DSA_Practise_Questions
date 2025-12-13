#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedian(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        if (n % 2 == 1)
            return arr[n / 2];
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
};

int main(){
    Solution s;
    vector<int> arr = {56, 67, 30, 79};
    cout << s.findMedian(arr);
    return 0;
}
