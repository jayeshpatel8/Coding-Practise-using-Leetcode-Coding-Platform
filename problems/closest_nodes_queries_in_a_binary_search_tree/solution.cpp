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
vector<int> arr;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        dfs(root);
        for (auto q : queries){
            auto it = lower_bound(begin(arr),end(arr),q);
            if (it != end(arr) && *it ==q) 
                ans.push_back({q,q});
            else
                ans.push_back({it == begin(arr) ?-1 : *prev(it),
                it==end(arr) ? -1 : *it});
        }
        return ans;
    }
   void dfs(TreeNode * root){
       if (!root) return;
       dfs(root->left);
       arr.push_back(root->val);
       dfs(root->right);
   }
};