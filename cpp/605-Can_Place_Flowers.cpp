#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maximum_flower = 0;
        int i = 0;
        if (n == 0) return true;
        if (flowerbed.size() == 1){
            if (flowerbed[0]==1){
                return false;
            } else return true;
        }

        while(i < flowerbed.size()){
            if (flowerbed[i] == 1){
                i = i+2;
            } else {
                if (i+1 == flowerbed.size()){
                    maximum_flower++;
                    i = i+2;
                    if (maximum_flower >= n) return true;
                }
                else if (flowerbed[i+1] == 1){
                    i = i+3;
                }
                else {
                    maximum_flower++;
                    i = i+2;
                    if (maximum_flower >= n) return true;
                }

            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> flowerbed {1,0};
    int n = 1;
    cout << sol.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}