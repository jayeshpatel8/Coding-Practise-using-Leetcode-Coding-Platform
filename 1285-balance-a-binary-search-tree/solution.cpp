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
    vector<int> node;
    TreeNode* balanceBST(TreeNode* root) {
        bt(root);
        int n = node.size();
        if (n<=2) return root;
        sort(begin(node),end (node));
        return bt2(0,n-1);
 

    }
    void bt(TreeNode* root){
        if (!root) return;
        node.push_back(root->val);
        bt(root->left);
        bt(root->right);
    }
    TreeNode* bt2(int s, int e){
        if (s > e) return NULL;
        int m = ( s + e )/  2;
        TreeNode* root = new TreeNode(node[m]);
        
        root->left = bt2(s,m-1);
        root->right = bt2(m+1,e);
        return root;
    }    
};
