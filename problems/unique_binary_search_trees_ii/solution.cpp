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
        return dfs(1,n);
    }
    vector<TreeNode*> dfs(int j,int n){
        if (j>n) return {nullptr};
        if (dp[j][n].empty()){            
            vector<TreeNode *> ans;
            for (int i=j; i<=n; i++){
                auto l = dfs(j,i-1);
                auto r = dfs(i+1,n);
                
                for (auto & l1: l)
                    for (auto& r1: r){
                        auto root = new TreeNode(i);
                        root->left = l1;
                        root->right = r1;
                        ans.push_back(root);
                    }
            }
            dp[j][n]=ans;
        }
        return dp[j][n];
    }
};