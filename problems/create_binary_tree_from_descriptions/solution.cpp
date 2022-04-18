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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        unordered_map<int,TreeNode*> map;
        for (auto & i : des){
            auto it = map.find(i[1]);
            
            if (map.count(i[1])==0)    
                map[i[1]]=new TreeNode(i[1]);
             
        }
  
        TreeNode * root;
        for (auto & i : des){
            auto p = i[0], c=i[1], l = i[2];
            auto it = map.find(p);
            TreeNode* node;
            if (map.count(p))
                node = map[p];
            else
                map[p]=node = new TreeNode(p),root=node;

            if (l)
                node->left = map[c];
            else
                node->right = map[c];

        }
        return root;
    }
};