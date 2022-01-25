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
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
    array<int,3> dfs(TreeNode* root){
        if (!root) return {50000,-50000,0};
        int v = root->val;
        
        auto a = dfs(root->left);
        auto b = dfs(root->right);
        
        if ((a[1]<v) && (b[0]>v)){
            int sum = a[2]+b[2]+v;
            ans = max(ans, sum);
            int l = root->left == 0 ? v : a[0];
            int r = root->right == 0 ? v : b[1];
            return {l,r,sum};
        }
        else
            return {INT_MIN,INT_MAX,0};
    }
};