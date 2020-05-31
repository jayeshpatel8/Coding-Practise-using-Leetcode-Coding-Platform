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
    bool isBalanced(TreeNode* root) {        
        return -1!=isBalanced_(root);         
    }
   int isBalanced_(TreeNode* root){
       if (!root ) return 0;
       int h1 = isBalanced_(root->left);
       if (h1 == -1) return h1;
       int h2 = isBalanced_(root->right);
       if (h2 == -1) return h2;
       if ( abs(h1-h2)<=1 )
           return max(h1,h2)+1;
       
       return -1;
   }
};