/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetric_(struct TreeNode* root1, struct TreeNode* root2){
    if (!root1 || !root2) return root1==root2;
    
    if ((root1->val != root2->val)) return false;
    
    if (!isSymmetric_(root1->left,root2->right) || !isSymmetric_(root1->right,root2->left))
        return false;
    return true;
    
}
bool isSymmetric(struct TreeNode* root){
    
    if (!root) return true;
    return isSymmetric_(root->left,root->right);
}