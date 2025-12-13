#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int sum = 0, ans = INT_MAX;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > x) {
                ans = min(ans, right - left + 1);
                sum -= arr[left++];
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int x = 51;
    cout << s.smallestSubWithSum(x, arr);
    return 0;
}
