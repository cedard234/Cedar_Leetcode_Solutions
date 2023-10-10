#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> quicksort(vector<int>& unsorted_array){
            if (unsorted_array.size() <= 1) return unsorted_array;
            else{
                int pivot = unsorted_array[0];
                vector<int> smaller;
                vector<int> larger;
                for(int i = 1; i< unsorted_array.size(); i++){
                    if (unsorted_array[i] < pivot){
                        smaller.insert(smaller.end(), unsorted_array[i]);
                    } else {
                        larger.insert(larger.end(), unsorted_array[i]);
                    }
                }
                vector<int> smaller_sorted = this->quicksort(smaller);
                vector<int> larger_sorted = this->quicksort(larger);
                vector<int> sorted;
                sorted.insert(sorted.end(), smaller_sorted.begin(), smaller_sorted.end());
                sorted.insert(sorted.end(), pivot);
                sorted.insert(sorted.end(), larger_sorted.begin(), larger_sorted.end());
                return sorted;
            }
        }
};

int main(){
    vector<int> unsorted {8,7,5,6,4,2,3,1,0};
    Solution sol;
    vector<int> sorted = sol.quicksort(unsorted);
    return 0;
}