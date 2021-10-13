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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return pre(preorder,0,preorder.size()-1);
    }
    TreeNode*  pre(vector<int>& preorder, int l, int r){
        if(l>r) return NULL;        
        int j =l+1 ,rv = preorder[l];
        while ( j<=r && (rv>preorder[j]) ){
            j++;
        }
        TreeNode  * root = new TreeNode(rv);        
        root->left = pre(preorder, l+1, j-1);
        root->right =   pre(preorder, j, r);

        return root;
    }
};