/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        
        TreeNode* lcm1 = lowestCommonAncestor(root->left,p,q);        
        TreeNode* lcm2 = lowestCommonAncestor(root->right,p,q);
        
        if (lcm1 && lcm2) return root;
        return lcm1 ? lcm1 : lcm2;
    }
};