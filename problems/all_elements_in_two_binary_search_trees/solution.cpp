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
    vector<int> ans;
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1, st2;
        
        while(root1 || root2 || !st1.empty() || !st2.empty() ){
            while(root1)
                st1.push(root1), root1= root1->left;
            while(root2)
                st2.push(root2), root2= root2->left;            
            if (st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val))
                ans.push_back(st1.top()->val), root1 =  st1.top()->right,st1.pop();
            else // (!st2.empty())
                ans.push_back(st2.top()->val), root2 =  st2.top()->right, st2.pop();            
        }
        return ans;
    }
    vector<int> getAllElements2(TreeNode* root1, TreeNode* root2) {
        dfs(root1);dfs(root2);
        sort(begin(ans),end(ans));
        return ans;
    }
    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }

};