#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int good = 0;
        for (int x : arr)
            if (x <= k) good++;
        
        int bad = 0;
        for (int i = 0; i < good; i++)
            if (arr[i] > k) bad++;
        
        int ans = bad;
        for (int i = 0, j = good; j < n; i++, j++) {
            if (arr[i] > k) bad--;
            if (arr[j] > k) bad++;
            ans = min(ans, bad);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {2, 1, 5, 6, 3};
    int k = 3;
    cout << s.minSwap(arr, k);
    return 0;
}
