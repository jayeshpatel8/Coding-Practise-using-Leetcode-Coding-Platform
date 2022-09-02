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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (q.empty() == false){
            int sz = q.size(), cnt = sz;
            long sum = 0;
            while (sz-- > 0){
                auto root = q.front();
                sum += root->val; q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back((double)sum / cnt);
        }
        return ans;
    }
};