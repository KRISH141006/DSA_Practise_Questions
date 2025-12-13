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
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        unordered_set<int> st;

        for(int x : a) st.insert(x);
        for(int x : b) st.insert(x);

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};
    vector<int> c = s.findUnion(a,b);
    printVector(c);

    return 0;
}