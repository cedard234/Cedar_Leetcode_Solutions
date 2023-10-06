#include<iostream> 
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        if (points.size() == 0) return 0;
        int count = 1;
        int previous = 0;
        for(int i = 1; i < points.size(); i++){
            if (points[i][0] <= points[previous][1]){
                //boom    
            }
            else {
                previous = i;
                count++;
            }
        }
        return count;
    }
};

int main(){
    vector<vector<int>> points {{10,16},{2,8},{1,6},{7,12}};
    Solution sol;
    cout << sol.findMinArrowShots(points) << endl;
    return 0;
}