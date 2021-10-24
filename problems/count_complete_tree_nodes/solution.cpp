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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl =0 ,hr = 0;
        TreeNode *t = root;
        
        while(t) t=t->left, hl++;
        t = root;
        while(t) t=t->right, hr++;
        
        if(hl==hr) return (1 << hl)-1;
        return 1 + countNodes(root->left) + countNodes(root->right) ;
    }
    int countNodes2(TreeNode* root) {
        if(!root) return 0;
        int h =0 ,level=0, cnt=0;
        TreeNode *t = root;
        
        while(t) t=t->left, h++;
        
        level = h -2;
        
        t =  root;
        while(level>=0){
            TreeNode * left = t->left;
            for (int l=0; l<level; l++) left  = left->right;
            
            if (left) cnt += 1<<level , t = t->right;
            else t = t->left;
            level--;
        }
        if(t) cnt ++;
        return cnt  + (1 << (h-1)) -1;
    }
};