#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size()-1;
        int sum;
        while(i < j){
            sum = numbers[i] + numbers[j];
            if (sum == target) return {i+1,j+1};
            else if (sum < target) i++;
            else j--;
        }
        return {0,0};
    }
};

int main(){
    Solution sol;
    vector<int> sorted_array {2,7,11,15};
    vector<int> pair = sol.twoSum(sorted_array, 9);
    return 0;
}