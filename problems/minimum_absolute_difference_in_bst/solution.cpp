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
long ans = 1e9;
    int getMinimumDifference(TreeNode* root) {
        long prev = -1e9;
        inorder(root, prev);
        return ans;
    }
    void inorder(TreeNode * root, long & prev){
        if (!root) return ;
        inorder(root->left,prev);
        ans= min (ans, root->val - prev);
        prev=root->val;
        inorder(root->right,prev);
    }
};