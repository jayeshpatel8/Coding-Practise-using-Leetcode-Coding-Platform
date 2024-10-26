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
int maxh=0 ,h_1[100001]={},h_2[100001]={} ;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        function<void(TreeNode*,int,int)> dfs =[&](TreeNode* root,int h, int left){
            if (!root) return ;
            auto v = root->val;
            if (left){
                h_1[v]=maxh;
                maxh=max(maxh,h);
                dfs(root->left,h+1,left);
                dfs(root->right,h+1,left);
            }
            else{
                h_2[v]=maxh;
                maxh=max(maxh,h);
                dfs(root->right,h+1,left);
                dfs(root->left,h+1,left);                
            }
            
        };
        dfs(root,0,0);
        maxh=0;
        dfs(root,0,1);
        vector<int> ans; 
        for (auto &q : queries){
            ans.push_back( max(h_1[q], h_2[q]));
        }
        return ans;        
        
    }
};
