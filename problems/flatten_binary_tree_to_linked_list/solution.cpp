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
    TreeNode * prev = NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
    TreeNode * preorder(TreeNode * root){
        if (!root) return root;
        if (!root->left){
            if (!root->right) return root;
            return preorder(root->right);
        }
        else{
            if (!root->right){
                root->right = root->left;
                root->left = NULL;
                return preorder(root->right);
            }
            else{
                auto r = root->right;
                root->right = root->left;
                root->left=NULL;
                auto l = preorder(root->right);
                l->right  = r;
                return preorder(r);
            }
        }
    }
};