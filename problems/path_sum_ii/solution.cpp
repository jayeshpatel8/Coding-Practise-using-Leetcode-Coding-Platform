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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        traverse(root, targetSum, path, 0);
        return ans;
    }
    void traverse(TreeNode* root, int t, vector<int>& path, int sum){
        if (!root) {
            return ;
        }
        
        int newsum = root->val + sum;
        path.push_back(root->val);                
        if (root->left || root->right){
            traverse(root->left,t,path,newsum);
            traverse(root->right,t,path,newsum);
        }
        else if (newsum == t) ans.push_back(path);
        
        path.pop_back();
    }
};