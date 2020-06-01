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
    void flatten(TreeNode* root) {
        //vector<int> res;
        if (!root) return ;
        flatten_(root);
       
    }
    TreeNode*  flatten_(TreeNode* root) {
        if (!root) return root;
       
        TreeNode * re=0, *le=0;
        if (root->left || root->right)
        {
            le=flatten_(root->left);
            re=flatten_(root->right);
        }
        else
            return root;

        
        if (le)
        { 
            le->right= root->right;
            root->right =root->left;
            root->left=0;
        }
        if (!re) 
                re=le;
        return re;                
    }
};