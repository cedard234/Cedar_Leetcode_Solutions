#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> selection_sort(vector<int> & unsorted){
            if (unsorted.size() <= 1) return unsorted;
            int max_index = 0;
            for (int i = 0 ; i < unsorted.size(); ++i){
                if (unsorted[max_index] < unsorted[i]){
                    max_index = i;
                }
            }
            swap(unsorted[max_index], unsorted[unsorted.size()-1]);
            int max = unsorted[unsorted.size()-1];
            vector<int> sliced(unsorted.begin(), unsorted.end()-1);
            sliced = this->selection_sort(sliced);
            sliced.push_back(max);
            return sliced;
        }

};

int main(){
    vector<int> unsorted{8,7,5,6,3,4,2,1,0};
    Solution sol;
    vector<int> sorted = sol.selection_sort(unsorted);
    return 0;
}