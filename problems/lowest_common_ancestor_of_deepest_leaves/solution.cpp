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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {        
        return ldl(root).first;
    }
    pair<TreeNode *,int> ldl(TreeNode * root){
        if (!root) return{NULL,0};
        
        pair<TreeNode *,int> l = ldl(root->left);
        pair<TreeNode *,int> r = ldl(root->right);
        if (l.second == r.second) return {root, 1 + l.second};
        
        if (l.second > r.second) return {l.first, 1 + l.second};
        else 
            return {r.first, 1 + r.second};
        
    }
};