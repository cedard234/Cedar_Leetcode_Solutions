#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        vector<int> arithmeticCount (nums.size(), 0);
        for (int i = 2; i < nums.size(); i++){
            if (nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
                arithmeticCount[i] = arithmeticCount[i-1]+1;
            }
        }
        return accumulate(arithmeticCount.begin(), arithmeticCount.end(), 0);
    }
};