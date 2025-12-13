#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int x : arr) cout << x << " ";
    cout << endl;
}

class Solution{
public:
    void sort012(vector<int>& arr){
        int c0 = 0, c1 = 0, c2 = 0;
        for(int x : arr){
            if(x == 0) c0++;
            else if(x == 1) c1++;
            else c2++;
        }
        int i = 0;
        while(c0--) arr[i++] = 0;
        while(c1--) arr[i++] = 1;
        while(c2--) arr[i++] = 2;
    }
};

int main(){
    Solution s;
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    s.sort012(arr);
    printVector(arr);
    return 0;
}
