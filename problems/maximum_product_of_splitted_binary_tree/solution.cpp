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
long ans = 0 ,tsum =0,mod=1e9 +7;
    int maxProduct(TreeNode* root) {
        tsum = totalsum(root);
        dfs(root);
        return ans%mod;
    }
    int totalsum(TreeNode * root){
        if (root)
            return root->val + totalsum(root->left) + totalsum(root->right);
            return 0;
    }
    long dfs(TreeNode* root) {
        if (!root) return 0;
        
        long  sum  =  root->val + dfs(root->left) + dfs(root->right);
        ans =  max(ans, (tsum - sum)* sum);
        return sum;
    }

};