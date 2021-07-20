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
        if (!root) return root;
        if (p == root || q == root) return root;
        
        if (root->val > p->val && root->val > q->val) 
            return lowestCommonAncestor(root->left,p,q);
        else if (root->val < p->val && root->val < q->val) 
            return lowestCommonAncestor(root->right,p,q);
        
        return root;
    }
};

/*
root -> left == root ||  root == right
root -> left < root < right else root < right -> left else right
root -> !left && root == right
root -> left == root &&  !right
*/