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
    unordered_map<int, int> prefixsum;
    int pathSum(TreeNode* root, int targetSum) {
        prefixsum[0] = 1;
        return dfs(root,targetSum, 0);
    }
    int dfs(TreeNode* root, int target, int sum){
        if(!root) return 0;
        int s = root->val +sum;
        int cnt = prefixsum[s-target];
        prefixsum[s]++;
        cnt += dfs(root->right,target, s);
        cnt += dfs(root->left,target, s);
        prefixsum[s]--;
        return cnt;
    }
};