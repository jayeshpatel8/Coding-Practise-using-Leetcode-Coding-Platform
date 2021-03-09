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
    TreeNode* addRow(TreeNode* root, int v, int d) {
        if(!root) return root;
        if(d==2){
                    
            TreeNode *n1 = new TreeNode(v);
            TreeNode *n2 = new TreeNode(v);

            n1->left= root->left;
            n2->right= root->right;
            root->left = n1;
            root->right = n2;            
        }
        else {
            addRow(root->left, v, d-1);
            addRow(root->right, v, d-1);
        }
            
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
       if (d==1){
           TreeNode * t = new TreeNode(v);
           t->left = root;
           return t;
       }   
        
        return  addRow(root, v, d);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            d--;
            int sz = q.size();
            while (sz-->0){
                if(d==1){
                    
                    TreeNode *t = q.front();q.pop();    
                    TreeNode *n1 = new TreeNode(v);
                    TreeNode *n2 = new TreeNode(v);
                    
                    n1->left= t->left;
                    n2->right= t->right;
                    t->left = n1;
                    t->right = n2;
                }
                else{                
                    TreeNode *t = q.front();q.pop();    
                    if(t->right) q.push(t->right);
                    if(t->left) q.push(t->left);
                }
            }            
        }

        return root;
    }
};