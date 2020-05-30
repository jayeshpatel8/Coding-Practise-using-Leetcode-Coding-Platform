/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#if 1
static struct TreeNode * p=0,*first=0,*mid,*second=0;
void recoverTree(struct TreeNode* root);
static int found = false;
void recoverTree1(struct TreeNode* root){
    
    if (!root || found) return ;
    
    
    recoverTree1(root->left);
     
#if 1    
    if (p && p->val >= root->val){        
        if (!first) {first = p;mid=root; }
        else
        {
            second = root;found = true;      
            return;
        }
    }
#endif    
    
    p = root;
    recoverTree1(root->right);        
  
}
void recoverTree(struct TreeNode* root)
{
    p=first=second=0;found = false;
    recoverTree1(root);


    
  int v = first->val;
    if (!second) second=mid;

    first->val=second->val;
    second->val=v;  


}
#endif