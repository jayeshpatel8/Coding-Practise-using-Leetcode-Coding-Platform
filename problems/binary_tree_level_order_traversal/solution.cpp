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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        queue<TreeNode*>q;
        vector<vector<int>> res;      
        q.push(root);
        vector<int> o;
        while (!q.empty()){
            int size = q.size();
            
            for (int i=0; i< size; i++)
            {
                root = q.front();q.pop();
                if (root){
                    if (root->left || root->right){
                        q.push(root->left);
                        q.push(root->right);
                    }
                    o.push_back(root->val);
                }                
            }
            res.push_back(o);
            o.clear();
        }
        return res;
    }
};