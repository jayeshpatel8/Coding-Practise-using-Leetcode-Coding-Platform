/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<TreeNode*> q{root},par(501);
        vector<bool> vis(501);
        
        vector<int> ans;
        int d=0;
        while (!q.empty()){
            vector<TreeNode*> t;
            for (auto &u : q){
                if (u->left) par[u->left->val]=u ,t.push_back(u->left);
                if (u->right) par[u->right->val]=u  ,t.push_back(u->right);
            }
            q.swap(t);
        }
        if (k==0) return {target->val};
        q.push_back(target);        
        while (!q.empty()){
            vector<TreeNode*> t;
            for (auto u : q){  
                if ( vis[u->val]) continue;
                vis[u->val]=1;              
                if (d==k){
                    ans.push_back(u->val); continue;
                }
                
                if (u->left) t.push_back(u->left);
                if (u->right) t.push_back(u->right);
                if (par[u->val])t.push_back(par[u->val]);
            }
            q.swap(t);
            d++;
        }
        
        return ans;    
    }
};