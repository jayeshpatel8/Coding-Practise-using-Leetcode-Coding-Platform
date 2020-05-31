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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        int diff = sum -root->val; 
        if (!root->right && !root->left)
            if(!diff)  return true;
            else return false;
        if (root->left && hasPathSum(root->left, diff))return true;
        if (root->right && hasPathSum(root->right, diff) )return true;
        //if (hasPathSum(root->left, diff) || hasPathSum(root->right, diff))
          //  return true;
        return false;
    }
};