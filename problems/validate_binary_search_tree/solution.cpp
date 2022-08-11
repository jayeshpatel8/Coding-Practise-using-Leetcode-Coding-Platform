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
    bool isValidBST(TreeNode* root, long  s=LONG_MIN, long m=LONG_MAX) {
        if (!root ) return true;
        if (root->val > s && root->val < m && isValidBST(root->left, s,root->val) && isValidBST(root->right, root->val,m)) return true;
        return false;
    }
};