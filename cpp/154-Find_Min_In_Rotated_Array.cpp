#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Trivial case: if middle == target, return middle
// from middle: if right is sorted and answer is on the right, compare findmin left and middle
// if right is not sorted, left must be sorted; compare 0 and findmin right
// Same applies to left

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else{
            int left = 0, right = nums.size()-1;
            int middle = left + (right - left)/2;
            if (nums[middle] < nums[right]){
                if (middle > 0) {
                    vector<int> sliced_left(nums.begin(), nums.begin()+middle);
                    return min(this->findMin(sliced_left), nums[middle]);
                } else {
                    return nums[middle];
                }
            } else if (nums[middle] > nums[left]) {
                if (middle < nums.size()-1) {
                    vector<int> sliced_right(nums.begin()+middle+1, nums.end());
                    return min(this->findMin(sliced_right),nums[left]);
                } else {
                    return nums[middle];
                }
            } else if (nums[middle] == nums[left]){
                vector<int> erase_leftmost(nums.begin()+1, nums.end());
                return this->findMin(erase_leftmost);
            } else{
                vector<int> erase_rightmost(nums.begin(), nums.end()-1);
                return this->findMin(erase_rightmost);
            }
        }
    }
};

int main(){
    vector<int> nums {1,3,3};
    Solution sol;
    cout << sol.findMin(nums) << endl;
    return 0;
}