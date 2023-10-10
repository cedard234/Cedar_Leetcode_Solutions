#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> mergesort(vector<int> unsorted_array){
            //implementation of mergesort
            if (unsorted_array.size() <= 1) return unsorted_array;
            else{
                int mid = unsorted_array.size()/2;
                vector<int> left;
                vector<int> right;
                for(int i = 0; i < mid; i++){
                    left.insert(left.end(), unsorted_array[i]);
                }
                for(int i = mid; i < unsorted_array.size(); i++){
                    right.insert(right.end(), unsorted_array[i]);
                }
                vector<int> left_sorted = this->mergesort(left);
                vector<int> right_sorted = this->mergesort(right);
                vector<int> sorted;
                int i = 0;
                int j = 0;
                while(i < left_sorted.size() && j < right_sorted.size()){
                    if (left_sorted[i] < right_sorted[j]){
                        sorted.insert(sorted.end(), left_sorted[i]);
                        i++;
                    } else {
                        sorted.insert(sorted.end(), right_sorted[j]);
                        j++;
                    }
                }
                while(i < left_sorted.size()){
                    sorted.insert(sorted.end(), left_sorted[i]);
                    i++;
                }
                while(j < right_sorted.size()){
                    sorted.insert(sorted.end(), right_sorted[j]);
                    j++;
                }
                return sorted;
            }
        }
};

int main(){
    vector<int> unsorted {2,1};
    Solution sol;
    vector<int> sorted = sol.mergesort(unsorted);
    return 0;
}