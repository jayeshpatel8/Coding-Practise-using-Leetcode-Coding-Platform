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
    int ans=0  ;
    unordered_set<TreeNode *> set={NULL};
    int minCameraCover(TreeNode* root){
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root , TreeNode * p  = 0) {
        if (!root) return ;
        dfs(root->left, root);
        dfs(root->right,root);
        if (!set.count(root->left)  || !set.count(root->right)){
            ans++;
            set.insert(root);
            //set.insert(root->left);
            //set.insert(root->right);
            set.insert(p);
        }
        else if (!p && !set.count(root)){
            ans++;
            set.insert(root);
            set.insert(p);
        }
        
    }
};