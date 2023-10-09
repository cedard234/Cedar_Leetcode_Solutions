#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//if 1, return 
//if middle != middle right && middle!= middle left
// return middle
// if middle == middle right and middle%2 == 0, answer is on the right
// if middle == middle left and middle%2 == 1, answer is on the right too
// if middle == middle right and middle%2 == 1, answer is on the left
// if middle == middle left and middle%2 == 0, answer is on the left too

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        else{
            int left = 0, right = nums.size() - 1;
            int middle = left + (right-left)/2;
            while(left < right && middle!= 0 && middle != nums.size()-1){
                if(nums[middle] != nums[middle-1] && nums[middle] != nums[middle+1]){
                    return nums[middle];
                } else if ((nums[middle] == nums[middle+1] && middle%2 == 0)||(nums[middle] == nums[middle-1]&&middle%2 == 1)){
                    left = middle+1;
                } else if ((nums[middle] == nums[middle+1] && middle%2 == 1)||(nums[middle] == nums[middle-1]&&middle%2 == 0)){
                    right = middle-1;
                }
                middle = left + (right - left) / 2;
           }
           return nums[left];
        }
    }
};

int main(){
    vector<int> nums {1,2,2,3,3};
    Solution sol;
    cout << sol.singleNonDuplicate(nums) << endl;
    return 0;
}