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
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty()){
            int sz = q.size();
            int nodes=sz;
            long avg=0;
            while(sz--){
                TreeNode *node = q.front(); q.pop();
                avg +=node->val;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            ans.push_back(avg*1.0/nodes);
        }
        return ans;
    }
};