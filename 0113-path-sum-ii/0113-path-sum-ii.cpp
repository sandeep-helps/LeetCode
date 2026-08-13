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
class Solution {
public:
    vector<vector<int>>result;
    void fill(TreeNode* root, int sum, vector<int>temp, int& targetsum){
        if(!root){
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(sum == targetsum){
                result.push_back(temp);
            }
        }
        fill(root->left, sum , temp , targetsum);
        fill(root->right, sum , temp , targetsum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum = 0;
        fill(root, sum , temp, targetSum);
        return result;
    }
};