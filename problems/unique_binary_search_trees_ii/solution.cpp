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
    vector<TreeNode*> dp[9][9]={};
    vector<TreeNode*> generateTrees(int n) {
        return build(1,n);
    }
    vector<TreeNode*> build(int i, int n){
        if (i>n) return {NULL};
        if (!dp[i][n].empty()) return dp[i][n];
        vector<TreeNode*> v;
        for (int j=i; j<=n; j++){        
            vector<TreeNode*> left = build(i,j-1);
            vector<TreeNode*> right = build(j+1,n);
            
            for (auto &l : left){
                for (auto &r : right)
                {
                    TreeNode* root = new TreeNode(j);
                    root->left = l;
                    root->right = r;
                    v.push_back(root);                        
                }
            }
        }
        return dp[i][n] = v;
    }
};