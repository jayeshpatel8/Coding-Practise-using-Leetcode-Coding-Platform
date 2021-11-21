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
    unordered_map<int,int> ino_idx;
    int i ;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i=0; i<inorder.size(); i++) 
            ino_idx[inorder[i]] = i;
        i = postorder.size()-1;
        return rec(0,postorder.size()-1, postorder);
    }
    TreeNode * rec(int st, int en,  vector<int>& po){
        if (st > en) return NULL;
        if (st == en) return new TreeNode (po[i--]);
        int val = po[i--] , idx = ino_idx[val];
        TreeNode * root = new TreeNode(val);
        root -> right = rec(idx+1,en,po);
        root -> left = rec(st,idx-1,po);
        return root;
    }
};