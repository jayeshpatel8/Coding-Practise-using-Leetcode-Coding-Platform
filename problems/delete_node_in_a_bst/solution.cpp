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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        if (root->val == key) {
            if (!root->right) return root->left;
            else if (!root->left) return root->right;
            TreeNode * t = root->right ;
            while(t->left) t = t->left;
            t->left = root->left; 
            return root->right;
        }
        else if (key < root->val) 
            root->left = deleteNode(root->left, key);
        else  
            root->right = deleteNode(root->right , key);
        
        return root;
    }
};