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
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> G(1e5+1);
        queue<TreeNode*> q1;
        q1.push(root);

        while (!q1.empty()){
            auto r = q1.front(); q1.pop();
            {
                if (r->left) {
                    G[r->val].push_back(r->left->val);
                    G[r->left->val].push_back(r->val);
                    q1.push(r->left);
                }
                if (r->right) {
                    G[r->val].push_back(r->right->val);
                    G[r->right->val].push_back(r->val);
                    q1.push(r->right);
                }
            }
        }

        int h = -1;
        vector<int> q{start};
        unordered_set<int> vis;        
        vis.insert(start);

        while(!q.empty()){
            vector<int> t;
            h++;
            for (auto u : q){
                for (auto v : G[u]){
                    if (vis.count(v) > 0) continue;
                    t.push_back(v);
                    vis.insert(v);
                }
            }
            
            q.swap(t);
        }
        return h;
    }
};