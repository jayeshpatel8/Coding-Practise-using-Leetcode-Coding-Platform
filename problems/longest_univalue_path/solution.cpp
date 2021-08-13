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
    int ans=0;
    int longestUnivaluePath(TreeNode* root){
        postorder(root);
        return ans;
    }
    int postorder(TreeNode* root) {        
        if(!root)             return 0;
        int l1=0, l2=0;
        if (root->left){
            l1 =  postorder(root->left);            
            l1 = (root->val == root->left->val) ? 1 + l1 : 0;
        }
        if (root->right){
            l2 =  postorder(root->right);
            l2 = ((root->val == root->right->val)) ? 1 + l2 : 0;
        }
        ans = max(ans, l1+l2);
        return max(l1,l2);
    }
};