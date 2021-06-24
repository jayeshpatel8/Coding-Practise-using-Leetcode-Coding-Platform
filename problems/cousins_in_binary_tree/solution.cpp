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
    
    bool isCousins(TreeNode* root, int x, int y) {
        if (root->val == x || root->val==y) return false;
        queue<TreeNode*> q;
        q.push(root);
        int p1=0,p2=0;
        //cout << p1  << " " << p2 << endl;
        while(!q.empty()){
            
            int sz  = q.size();
            while(sz--){
                TreeNode * n = q.front();  q.pop();
                if (n->left ){
                    if((n->left->val == x || n->left->val == y)){
                        if (p1) p2 = n->val; else p1 = n->val;
                    }
                    else
                        q.push(n->left);
                    
                }
                if (n->right){
                    if  (n->right->val == x || n->right->val == y) { 
                        if (p1) p2 = n->val; 
                        else p1 = n->val;
                    }else
                        q.push(n->right);
                }
                        
            }
            if (p1 || p2) {
                //cout << p1  << " " << p2 << endl;
                if (!p1 || !p2) return false;
                return (p1 != p2);
            }
            
        }
        return false;
    }
};