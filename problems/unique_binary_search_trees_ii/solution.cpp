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
   // vector<TreeNode*> o;
    map<pair<int,int>,vector<TreeNode*>> dp;
    vector<TreeNode*> generateTrees(int n) {
        if (n==0){
            return {};
        }else{
            return generateTrees(1, n);
        }
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {res.push_back(NULL);;return res;}
        if (dp.count({start,end})) return dp[{start,end}];
        
        vector<TreeNode*> l,r;
        for (int i=start; i<=end; i++)
        {
            l = generateTrees(start,i-1);
            r = generateTrees(i+1,end);
            
            for (auto  &&lt:l)
                for (auto && rt:r){
                    TreeNode * root = new TreeNode(i);
                    root->left=lt;
                    root->right=rt;
                    res.push_back(root);
                }
        }
        return dp[{start,end}]=res;
    }
};