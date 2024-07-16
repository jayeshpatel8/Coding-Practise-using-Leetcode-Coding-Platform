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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s ,t;

            dfs(root, startValue, s);
            dfs(root, destValue,t);
            int i = 0; 
            for (; i< min(s.size(), t.size()); i++){
                if (s[i] != t[i]) break;
            }
            return string(s.size()-i,'U') + t.substr(i);
        return "";
    }
    bool dfs(TreeNode* root, int v, string &  s){
        if (!root) return false;
        if (root->val == v)
            return true;
        
        s.push_back('L');
        if (dfs(root->left,v,s))
            return true;
        
        s.pop_back();
        s.push_back('R');
         
        if (dfs(root->right,v,s))
            return true;
        
        s.pop_back();
        return false;
    }
};
