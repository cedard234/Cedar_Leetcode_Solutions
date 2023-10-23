/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(ans, root, "");
        return ans;
    }

    void dfs(vector<string>& ans, TreeNode* node, string position){
        if (node == nullptr) return; //this is an invalid position
        if (node->left==nullptr && node->right == nullptr){
            if (position.empty()) ans.push_back(to_string(node->val));
            else ans.push_back(position+"->"+to_string(node->val));
            return;
        } //this is a leaf
        else{ //this is a node with child node at least 1
            if (position.empty()){
                dfs(ans, node->left, to_string(node->val));
                dfs(ans, node->right, to_string(node->val));
            }
            else {
                dfs(ans, node->left, position + "->" + to_string(node->val));
                dfs(ans, node->right, position + "->" + to_string(node->val));
            }

        }
    }
};