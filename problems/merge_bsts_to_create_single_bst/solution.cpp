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
    unordered_map<int,int> freq;
    unordered_map<int,TreeNode*> root;
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for (auto &r : trees){
            freq[r->val]++;
            if (r->left) freq[r->left->val]++;
            if (r->right) freq[r->right->val]++;
            root[r->val]=r;
        }
        for (auto &r : trees){
            if (freq[r->val]==1){
                root.erase(r->val);
                return (merge(r) && root.empty())? r: NULL;
            }
        }
        
        return NULL;
    }
    bool merge(TreeNode * r, int minv=INT_MIN, int maxv=INT_MAX){
        if (r==NULL) return true;
        
        if (r->val <= minv || r->val >=maxv) return false;
        
        if (!r->left && !r->right){
            auto it = root.find(r->val);
            if (it == root.end()) return true;
            r->left = it->second->left;
            r->right = it->second->right;
            root.erase(it);
        }
        return merge(r->left,minv,r->val) && merge(r->right, r->val, maxv);  
    } 
};