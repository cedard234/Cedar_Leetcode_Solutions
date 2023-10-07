#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long int square = 0;
        if (c < 0) return false;
        for (int i = 0; i< int(sqrt(c))+1; i++){
            long int remain = c - i*i;
            long int j = sqrt(remain);
            if (j*j == remain) return true;
        }
        return false;
    }
};

int main(){
    int c = 25;
    Solution sol;
    cout << sol.judgeSquareSum(c) << endl;

}