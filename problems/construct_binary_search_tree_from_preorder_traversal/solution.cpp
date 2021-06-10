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
    int idx=0;
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return bst(pre,  0 ,pre.size()-1);
    }
    TreeNode * bst( vector<int>& pre, int s, int e ){
        if (s>e) return NULL;
        TreeNode * root = new TreeNode(pre[idx]);
        int i = s+1;
         while (i< pre.size() && pre[i]<pre[idx])i++;
        idx++;
        
        root->left = bst(pre, s+1,i-1);
        root->right = bst(pre, i,e);
        return root;
    }
};