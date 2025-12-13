#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubset(vector<int>& a, vector<int>& b) {
        unordered_map<int,int> mp;
        for (int x : a) mp[x]++;
        for (int x : b) {
            if (mp[x] == 0) return false;
            mp[x]--;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b = {11, 3, 7, 1, 7};
    cout << s.isSubset(a, b);
    return 0;
}
