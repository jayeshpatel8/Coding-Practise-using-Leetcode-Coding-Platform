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
    TreeNode* first =0 , * prev = 0,*second=0;
    void recoverTree(TreeNode* root){
        recoverTree1(root);
        swap(first->val,second->val);
    }
    void recoverTree1(TreeNode* root){
        if (!root) return;
        recoverTree1(root->left);
        int val  = root->val;        
        if (prev && prev->val >= val)
        {
            if (!first) first=prev;
            second = root;
        }
        prev=root;
        
        recoverTree1(root->right);
    }
};