#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {{}};
        vector<vector<int>> permutations;
        backtrace(nums, 0, permutations);
        return permutations;
    }

    void backtrace(vector<int>& nums, int index, vector<vector<int>>& permutations){
        if (index == nums.size()-1) {
            permutations.push_back(nums);
        } else{
            for (int i = index; i < nums.size(); i++){
                swap(nums[index], nums[i]);
                backtrace(nums, index+1, permutations);
                swap(nums[index], nums[i]);
            }
        }
    }    

};

int main (){
    vector<int> nums {1,2,3};
    Solution sol;
    vector<vector<int>> permutations;
    permutations = sol.permute(nums);
    return 0;
}