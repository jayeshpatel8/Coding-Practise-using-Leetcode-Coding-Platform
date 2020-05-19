/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST_(struct TreeNode* root,  long long max,long long min){
    if (!root) return true;

    
    if ((root->val >= max) || ( root->val <= min)) return false;
      
    return isValidBST_(root->left,root->val,min) && isValidBST_(root->right,max,root->val);
}

bool isValidBST(struct TreeNode* root){
    if (!root) return true;
    int minl,maxl,minr,maxr;
    return isValidBST_(root,LONG_MAX,LONG_MIN);
}