#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s) 
    {
        // Step 1: Sort the input string in ascending order of characters
        sort(s.begin(), s.end());

        // Initialize variables for counting and indexing
        int n = s.size(); // Get the length of the sorted string
        int cnt = 0; // Initialize count for characters
        
        // Initialize a max heap priority queue to store pairs of (count, substring)
        priority_queue<pair<int, string>> pq;
        
        int i(0), j(0); // Initialize indices for character grouping

        // Step 2: Iterate through the sorted string to group characters by frequency
        while (i < n && j <= n) {
            if (s[i] == s[j]) {
                // If characters are the same, extend the group and increment count
                j++;
                cnt++;
            } else {
                // If characters are different, push the count and substring to the priority queue
                if (j == n) {
                    pq.push({cnt, s.substr(i, j - i)});
                    j++;
                } else {
                    pq.push({cnt, s.substr(i, j - i)});
                    i = j; // Update the start index of the next character group
                    cnt = 0; // Reset count for the next character group
                }
            }
        }

        s.clear(); // Clear the input string to construct the sorted result
        
        // Step 3: Construct the result string by popping pairs from the priority queue
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            s = s + it.second; // Append the substring based on the count
        }

        // Return the final result string
        return s;
    }
};

int main(){
    string s = "Hello world";
    Solution sol;
    cout << sol.frequencySort(s) << endl;
}