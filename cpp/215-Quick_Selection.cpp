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

        return this->QuickSelect(nums, 0, nums.size()-1, nums.size()-k+1);
    }

    int QuickSelect(vector<int> &a, int left, int right, int k)
    {
        int pivot = a[ left ];

        int i = left;
        int j = right;
        while( i < j )
        {
            //NOTE: ">=" not ">"
            while ( a[j] >= pivot && i < j )
                j--;
            a[i] = a[j];

            while ( a[i] <= pivot && i < j )
                i++;
            a[j] = a[i];
        }
        a[i] = pivot;

        //there are i+1 numbers from a[0] to a[i]
        if( k < i + 1 )
            return QuickSelect( a, left, i - 1 , k);
        else if( k > i + 1 )
            return QuickSelect( a, i + 1, right, k);
        else
            return a[i];
    }
};

int main(){
    vector<int> nums{3,2,1,5,6,4};
    int target = 2;
    Solution sol;
    cout << sol.findKthLargest(nums,target) << endl;
    return 0;
}