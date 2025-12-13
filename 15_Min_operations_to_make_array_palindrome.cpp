#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalin(int x) {
        int rev = 0, t = x;
        while (t) {
            rev = rev * 10 + (t % 10);
            t /= 10;
        }
        return rev == x;
    }
    
    bool PalinArray(vector<int>& arr) {
        for (int x : arr) {
            if (!isPalin(x)) return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> arr = {111, 222, 333, 444, 555};
    cout << s.PalinArray(arr);
    return 0;
}
