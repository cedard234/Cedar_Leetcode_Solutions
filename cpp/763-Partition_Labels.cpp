#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int>> alphabet_intervals;
        for (int i = 0; i< s.length(); i++){
            if (alphabet_intervals.find(s[i]) == alphabet_intervals.end()){
                alphabet_intervals[s[i]] = {i,i};
            }
            else {
                alphabet_intervals[s[i]][1] = i;
            }
        }
        //alphabet_intervals stores all interval information of all chars
        vector<vector<int>> intervals;
        for (auto& pair : alphabet_intervals){
            intervals.push_back(pair.second);
        }

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });
        vector<int> partition;
        int max_interval_tail = intervals[0][1];
        int previous = -1;
        for (int i = 1; i < intervals.size(); i++){
            if (max_interval_tail > intervals[i][0] && max_interval_tail > intervals[i][1]){
            }
            else if (max_interval_tail > intervals[i][0] && max_interval_tail < intervals[i][1]){
                max_interval_tail = intervals[i][1];
            }
            else if (max_interval_tail <= intervals[i][0] && max_interval_tail <= intervals[i][1]){
                partition.push_back(max_interval_tail - previous);
                previous = max_interval_tail;
                max_interval_tail = intervals[i][1];
            }
        }
        if (max_interval_tail > previous){
            partition.push_back(max_interval_tail-previous);
        }
        // partition.push_back(max_interval_tail - previous);

        return partition;
    }
};

int main(){
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    vector<int> partition_table = sol.partitionLabels(s);
    for (int i = 0; i< partition_table.size(); i++){
        cout << partition_table[i] << endl;
    }
    return 0;
}