#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }

        vector<pair<int, int>> frequencyVec;
        for (auto& p : frequency) {
            frequencyVec.emplace_back(p.first, p.second);
        }

        sort(frequencyVec.begin(), frequencyVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second > b.second;
        });

        vector<int> topk;
        for (int i = 0; i < k; i++) {
            topk.push_back(frequencyVec[i].first);
        }

        return topk;
    }
};

int main(){
    Solution sol;
    vector<int> nums{1,1,1,2,2,3};
    vector<int> topk = sol.topKFrequent(nums, 2);
    return 0;
}