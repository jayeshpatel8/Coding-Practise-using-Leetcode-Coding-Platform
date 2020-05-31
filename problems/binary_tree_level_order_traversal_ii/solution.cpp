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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int>lvl;
            for (int i =0; i< s; i++){
                TreeNode * r = q.front();q.pop();
                
                if (r){
                    lvl.push_back(r->val);
                    q.push(r->left);
                    q.push(r->right);
                }
            }
            if (lvl.size())
             res.push_back(lvl);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};