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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        //max(ans, dfs(root,0));
        dfs(root);
        return ans-1;
    }
    array<int,2> dfs(TreeNode* root){
        if (!root) return {0,0};
        int r = (dfs(root->right)[0]) +1;
        int l = (dfs(root->left)[1]) +1;        
        ans= max({ans,r,l});
        
        return {l,r};
    }    
    int dfs2(TreeNode* root, int dir){
        if (!root) return 0;
        int r = (dfs2(root->right,1)) +1;
        int l = (dfs2(root->left,0)) +1;
        int k = dir ==0 ? r : l;
        ans= max({ans,r,l});
        
        return k;
    }
};