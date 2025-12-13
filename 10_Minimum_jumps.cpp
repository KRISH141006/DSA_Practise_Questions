#include<bits/stdc++.h>
#include"myutilities.h"
using namespace std;

class Solution{
public :
    int minJumps(vector<int>& arr){
        int n = arr.size();

        int jmp = 0;
        int farthest = 0;
        int currEnd = 0;

        for(int i=0;i<n-1;i++){
            farthest = max(farthest,i+arr[i]);

            if(i == currEnd){

                jmp++;
                currEnd = farthest;

                if(currEnd >= n-1){
                    return jmp;
                }

                if(i == currEnd) return -1;
            }
        }

        return -1;
    }
};
int main(){
    Solution s;
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout<<s.minJumps(arr);
    return 0;
}