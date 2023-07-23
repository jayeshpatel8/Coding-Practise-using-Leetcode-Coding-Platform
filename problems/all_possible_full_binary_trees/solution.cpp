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
 unordered_map<int, vector<TreeNode *>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        //memset(dp,-1,sizeof(dp));
        return dfs(n);
    }
    vector<TreeNode *> dfs(int n){
        vector<TreeNode *> ans;
        if (n < 1 || (n&1)==0) return dp[n]=ans;
        if (dp.count(n) ) return dp[n];
        
        if (n == 1) {
            // if n is eql to 1 simply return
            ans.push_back(new TreeNode(0));
            dp[1] = ans;
            return ans;
        }
        for (int i=1; i<n; i++){
            auto l = dfs(i), r = dfs(n-1-i);
            for (auto l1 : l)
                for (auto r1: r){
                    auto *root = new TreeNode(0);
                    root->left = l1;
                    root->right=r1;
                    ans.push_back(root);
                }
        }
        return dp[n] = ans;
    }
};