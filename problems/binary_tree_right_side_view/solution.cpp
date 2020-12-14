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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
                res.push_back( q.front()->val);
                int cnt=q.size();
                while (cnt--){
                    TreeNode * i = q.front(); q.pop();
                    if (i->right)  q.push(i->right);
                    if (i->left)   q.push(i->left);                                                           }
        }
        return res;
        
    }
 
};