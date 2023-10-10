#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
    public:
        void insertion_sort(vector<int> & unsorted){
            for (int i = 0 ; i < unsorted.size() ; ++i ){
                for (int j = i ; j > 0 && unsorted[j] < unsorted[j-1]; j--){
                    swap(unsorted[j], unsorted[j-1]);
                }
            }
        }
};

int main(){
    vector<int> unsorted{8,7,5,6,3,4,2,1,0};
    Solution sol;
    sol.insertion_sort(unsorted);
    return 0;
}