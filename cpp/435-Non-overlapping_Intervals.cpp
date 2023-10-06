#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        int interval_count = 0;
        int counter = 1;
        int last_interval = 0;
        if (intervals.size() < 1){
            return 0;
        }
        else{
            sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b){
                return a[1] < b[1];
            });
            while(counter < intervals.size()){
                if (intervals[counter][0] < intervals[last_interval][1]){
                    interval_count++;
                }
                else{
                    last_interval = counter;
                }
                counter++;
            }
        }
        return interval_count;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> interval {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(interval) << endl;
    return 0;
}