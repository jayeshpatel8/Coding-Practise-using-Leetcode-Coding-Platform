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
    int idx=0 , N;
    TreeNode* recoverFromPreorder(string s) {
        i = dc = 0;

       return dfs(s,0);   
    }
    int i , dc;
    TreeNode* dfs(string s, int d){
       
        if (d != dc  ) return NULL;
        int n=0;
        while(i<s.size() && s[i]!='-'){
           n = n * 10 + s[i++]-'0';
        }
        TreeNode* root  = new TreeNode(n);
                
        dc=0;
        if (i == s.size()) return root;
        
        while (s[i]=='-')dc++,i++;

        root->left = dfs(s,d+1);
        root->right = dfs(s,d+1);
        return root;
    }
};