#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int> &a, vector<int> &b){
            if (a[0] != b[0]){
                return a[0] > b[0];
            } else{
                return a[1] < b[1];
            }
        });
        vector<vector<int>> sorted_queue;
        for (int i = 0; i < people.size(); i++){
            sorted_queue.insert(sorted_queue.begin()+people[i][1], people[i]);
        }
        return sorted_queue;
    }
};

int main (){
    vector<vector<int>> out_of_order_queue {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution sol;
    vector<vector<int>> in_order_queue;
    in_order_queue = sol.reconstructQueue(out_of_order_queue);
    return 0;
}