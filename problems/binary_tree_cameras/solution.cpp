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
enum {
  COVERED_NO_CAMERA=0,
  NOT_COVERED_NO_CAMERA=1,
  COVERED_CAMERA=2
};
class Solution {
public:
    int ans=0  ;
    
    int minCameraCover(TreeNode* root){
        
        if (NOT_COVERED_NO_CAMERA == dfs(root) )
            ans++;
        return ans;
    }
    int dfs(TreeNode *root){
        if (!root) return COVERED_NO_CAMERA;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l==NOT_COVERED_NO_CAMERA || r == NOT_COVERED_NO_CAMERA){
            ans++;
            return COVERED_CAMERA;
        }
        else if (l==COVERED_CAMERA || r==COVERED_CAMERA) return COVERED_NO_CAMERA;
        else return NOT_COVERED_NO_CAMERA;
    }
    unordered_set<TreeNode *> set={NULL};
    int min2CameraCover(TreeNode* root){
        dfs2(root);
        return ans;
    }
    void dfs2(TreeNode* root , TreeNode * p  = 0) {
        if (!root) return ;
        dfs2(root->left, root);
        dfs2(root->right,root);
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