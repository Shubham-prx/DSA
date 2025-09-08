#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxSum,temp=0;
        int l=0,r=k;
        for(int i=0;i<k;i++){
            temp+=nums[i];
        }
        maxSum=temp;
        while(r<nums.size()){
            temp=temp-nums[l]+nums[r];
            if(maxSum<temp)
                maxSum=temp;
            l++;
            r++;
        }
        return maxSum/(double)k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    double result = sol.findMaxAverage(nums, k);
    cout << result;
    return 0;
}
