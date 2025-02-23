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
    int  h=0, i=0;
    TreeNode* recoverFromPreorder(string traversal) {
        
        return dfs(traversal,0);
        
    }
    TreeNode *dfs( string & s, int h1){
        if (h != h1) return                nullptr;
        
        int v=0;
        while (  i< s.size() && isdigit(s[i])) v= v * 10 + (s[i++] - '0');
        auto * root = new TreeNode(v);
        
        
        h=0;
        while (  i< s.size() && '-'==s[i]) i++ , h++;
        
        
        root->left = dfs(s,h1+1);
        root->right = dfs(s,h1+1);
        
        return root;

    }
};
