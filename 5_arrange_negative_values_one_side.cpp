#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &arr){
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;
}

class Solution{
public :
    void rearrangeNegs(vector<int> &arr){
        int j = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    s.rearrangeNegs(arr);
    printVector(arr);

    return 0;
}