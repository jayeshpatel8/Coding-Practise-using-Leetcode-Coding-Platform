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
    unordered_map<int,int> prefixsum;
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        prefixsum[0]++;
        return trav(root, targetSum);
    }
    int trav(TreeNode* root, int t, int sum =0){
        if (!root) return 0;
        int newsum = sum + root->val;
        
        int cnt = prefixsum[newsum-t];
        prefixsum[newsum]++;
        cnt += trav(root->left, t, newsum);
        cnt += trav(root->right, t, newsum);
        prefixsum[newsum]--;
        
        return cnt;
    }
};