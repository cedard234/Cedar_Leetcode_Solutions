#include<iostream>
#include<algorithm>
#include<vector>
#include<random>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < 2) return nums[k];
        // shuffle the vector
        random_device rd;
        mt19937 g(rd());
        shuffle(nums.begin(), nums.end(), g);

        return this->quick_selection(nums, k-1, 0, nums.size()-1);
    }

    int quick_selection(vector<int> & nums, int target, int left, int right){
        if (left == right) return nums[left];

        // quick select whichever element
        int i=left, j=left;
        while(j<right){
            if (nums[j] <= nums[right]){
                j++;
            } else {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        swap(nums[i], nums[right]);
        if (i == target) return nums[i];
        else if (i < target){
            return this->quick_selection(nums, target-i, i, right);
        } else {
            return this->quick_selection(nums, i-target, left, i-1);
        }

    }
};

int main(){
    vector<int> nums{3,2,1,5,6,4};
    int target = 2;
    Solution sol;
    cout << sol.findKthLargest(nums,target) << endl;
    return 0;
}