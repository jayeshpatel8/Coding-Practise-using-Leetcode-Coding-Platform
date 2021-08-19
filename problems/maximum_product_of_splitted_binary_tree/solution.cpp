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
    long ans=0 ,msum , mod =  1e9 + 7;
    int maxProduct(TreeNode* root) {
        msum = sum(root);
        mproduct(root);
        return ans %mod; 
    }
    long sum(TreeNode * root){
        if (root) return root->val + sum(root->left) + sum(root->right);
        return 0;
    }
    long mproduct(TreeNode * root){
        if (!root) return 0;
        long l = mproduct(root->left);
        long r = mproduct(root->right);
        ans = max({ans, (msum - l) * l, (msum-r)*r});
        return root->val + l + r;
    }
};