#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<vector<int>> ans;
       permute(ans, nums, 0);
       return ans; 
    }

    void permute(vector<vector<int>>& ans, vector<int>& nums, int index){
        if (index == nums.size()){
            if (find(ans.begin(), ans.end(), nums) == ans.end())
                ans.push_back(nums);
        } 
        for (int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            permute(ans, nums, index+1);
            swap(nums[i], nums[index]);
        }
    }
};

int main(){
    vector<int> nums {2,2,1,1};
    Solution sol;
    vector<vector<int>> permutations = sol.permuteUnique(nums);
    return 0;
}