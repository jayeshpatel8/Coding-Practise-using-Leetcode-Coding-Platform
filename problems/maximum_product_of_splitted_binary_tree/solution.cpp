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
    long maxp=0, mod = 1e9 + 7, maxsum=0;
    int maxProduct(TreeNode* root) {
        maxSum(root);
        maxP(root);
        return  maxp % mod;
    }
    void maxSum(TreeNode* root){
        if(!root) return;
        maxsum+=root->val;
        maxSum(root->left);
        maxSum(root->right);
    }
    long maxP(TreeNode* root) {
        if(!root) return 0;
        long l = maxP(root->left);
        long r = maxP(root->right );
        long sum = root->val + r + l;
        maxp = max(maxp, (maxsum - sum) * sum) ;
        return root->val + l + r;
    }
};