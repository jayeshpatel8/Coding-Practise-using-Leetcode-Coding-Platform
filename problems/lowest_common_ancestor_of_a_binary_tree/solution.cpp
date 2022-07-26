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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root == p || root == q) return root;
        auto l = lowestCommonAncestor(root->left,p,q);
        auto r = lowestCommonAncestor(root->right,p,q);
        if (l == NULL) return r;
        else if (r==NULL) return l;
        else return root;
    }
    unordered_set<TreeNode*> set;
    TreeNode * ans = 0;
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p);

        dfs1(root,q);
        return ans;
    }
    bool dfs(TreeNode * root, TreeNode * n){
        if (!root) return false;
        if (root == n) {
            set.insert(n); 
            return true;
        }
        if (dfs( root->left, n ) || dfs( root->right, n )){
            set.insert(root);
            return true;
        }
        return false;
    }
    bool dfs1(TreeNode * root, TreeNode * n){
        if (!root) return false;
        if (root == n) {
            if (set.count(n) ) ans = n;
            return true;
        }
        if (dfs1( root->left, n ) || dfs1( root->right, n )){
            if (!ans && set.count(root) )  ans = root;
            return true;
        }
        return false;
    }
};