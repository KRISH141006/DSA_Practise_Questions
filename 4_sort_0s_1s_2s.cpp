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
    void sort012(vector<int>& arr){
        int c0=0,c1=0,c2=0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == 0) c0++;
            if(arr[i] == 1) c1++;
            if(arr[i] == 2) c2++;
        }
        int i = 0;
        while(c0 || c1 || c2){
            if(c0) {
                arr[i] = 0;
                c0--;
            }
            else if(c1){
                arr[i] = 1;
                c1--;  
            } 
            else if(c2){
                arr[i] = 2;
                c2--;
            }
            i++;
        }
    }
};
int main(){
    Solution s;
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    s.sort012(arr);
    printVector(arr);    
    return 0;
}