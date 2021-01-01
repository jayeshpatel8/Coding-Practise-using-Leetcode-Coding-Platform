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
    int path=0,num=0;
    int pseudoPalindromicPaths (TreeNode* root) {
        pal(root,num)       ;
        return  path;
    }
    void pal(TreeNode * root, int num){
        if (!root) return ;
        num ^= 1 << root->val;
        
        if (!root->left && !root->right) {
                if ((num & num-1)==0) 
                    path++;
           return;
        }
        
        pal(root->left,num) ;
        pal(root->right,num);
        return;        
    }
};