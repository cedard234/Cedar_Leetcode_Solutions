#include<iostream>
#include<algorithm>

class Solution {
public:
    int climbStairs(int n) {
        return count(n);
    }

    int count(int n){
        if (n == 1) return 1;
        if (n == 2) return 2;
        return count(n-1)+count(n-2);
    }
};