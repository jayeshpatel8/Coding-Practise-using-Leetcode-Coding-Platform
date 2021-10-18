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
    int dx=-1,dy=-2, px=-1,py=-2;
    bool isCousins(TreeNode* root, int x, int y) {
        depth(root, x, y);
        return (px!= py) && (dx  == dy);
    }
    void depth(TreeNode* root, int x, int y, int i = 0){
        if (!root) return ;
        i++;
        if (root->right)
        {
           if (root->right->val == x ) {
                   dx = i+1; px=root->val;
           }
            else if (root->right->val == y ) {                
                    dy = i+1; py=root->val;
            } 
        }
        if (root->left)
        {
           if (root->left->val == x ) {
               dx = i+1; px=root->val;
           }
            else if (root->left->val == y ) {
                dy = i+1; py=root->val;
            } 
        }
        depth(root->right, x,y,i), depth(root->left, x,y,i);
        return ;
    }
};