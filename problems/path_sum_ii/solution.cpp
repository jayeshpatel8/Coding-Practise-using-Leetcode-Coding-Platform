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

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> o;
        helper(root,sum,res,o);
        return res;
    }
    void helper(TreeNode* root, int sum,vector<vector<int>> & res, vector<int>& o) {
                if (!root) return ;
        o.push_back(root->val);
        if (sum == root->val && !root->left && !root->right)
        {
             res.push_back(o);o.pop_back(); return ;
        }
        helper(root->right,sum-root->val,res,o);
        helper(root->left,sum-root->val,res,o);
        o.pop_back();
    }
};