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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        bool left = true;
        while (!q.empty()){
            int sz = q.size();
            vector<int> cur;
            while (sz-- > 0){
                auto n = q.front(); q.pop();
                cur.push_back(n->val);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
                
            }
            if (!left) reverse(begin(cur),end (cur));
            left = !left;
            ans.push_back(cur);
        }
        return ans;
    }
};