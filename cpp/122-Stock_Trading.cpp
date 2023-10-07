#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        else{
           int profit = 0;
           for (int i = 1; i< prices.size(); i++){
                if (prices[i] > prices[i-1]){
                    profit += prices[i] - prices[i-1];
                }
           } 
           return profit;
        }
    }
};

int main (){
    Solution sol;
    vector<int> prices {5,4,3,2,1};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}