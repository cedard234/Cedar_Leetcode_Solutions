#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int left = 1, right = x;
        int middle, sqrt;
        while(left <= right){
            middle = left + (right - left)/2;
            sqrt = x/middle;
            if (middle == sqrt) return middle;
            else if (middle > sqrt){
                right = middle-1;//middle**2 > x, select left
            } else{
                left = middle+1;
            }
        }
        return right;
}
};

int main(){
    int square = 8;
    Solution sol;
    cout << sol.mySqrt(square) << endl;
    return 0;
}