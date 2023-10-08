#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBound = this->findLowerBound(nums, target);
        int upperBound = this->findUpperBound(nums, target);
        return {lowerBound, upperBound}; 
    }

    int findLowerBound(vector<int>&nums, int target){
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0]==target?0:-1;
        int left = 0, right = nums.size()-1;
        int middle;
        while(left < right){
            middle = left + (right-left)/2;
            if (nums[middle]>=target){
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return nums[right]==target?right:-1;
    }
    
    int findUpperBound(vector<int>&nums, int target){
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return nums[0]==target?0:-1;
        int left = 0, right = nums.size()-1;
        int middle;
        while(left < right){
            middle = left + (right-left)/2;
            if (nums[middle]<=target){
                left = middle;
            } else {
                right = middle-1;
            }
        }
        return nums[left]==target?left:-1;
    }
};

int main(){
    vector<int> nums {5,7,7,8,8,10};
    int target = 8;
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    return 0;
}