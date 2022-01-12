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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return (new TreeNode(val));
        TreeNode* prev=root, *cur=root;
        while (cur){
            prev=cur;
            if (val < cur->val )
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (val < prev->val )
            prev->left = (new TreeNode(val));
        else
            prev->right = (new TreeNode(val));
        return root;
    }
    TreeNode* insertIntoBST2(TreeNode* root, int val) {
        if (!root) return (new TreeNode(val));
        if (val < root->val)
            root->left = insertIntoBST(root->left,val);
        else
            root->right = insertIntoBST(root->right,val);
        return root;
    }
};