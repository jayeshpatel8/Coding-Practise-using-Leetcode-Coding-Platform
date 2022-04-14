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
    TreeNode* searchBST(TreeNode* root, int val, int l=INT_MIN,int r=INT_MAX) {
        if (!root || root->val == val) return root;
        if (root->val > r ||root->val < l ) return NULL;
        if  (root->val < val)
            return searchBST(root->right,val,root->val,r);
        else 
            return searchBST(root->left,val,l,root->val);
    }
};