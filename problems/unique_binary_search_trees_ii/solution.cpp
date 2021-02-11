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
    unordered_map<size_t , vector<TreeNode*>> DP;
    vector<TreeNode*> generateTrees(int n) {        
        
        return gt(1,n);
    }
   vector<TreeNode*>  gt(int start, int end){
        vector<TreeNode*> v;
        if (start > end) return vector<TreeNode*> {NULL};
       size_t id = (size_t)start<<32|end;
       if(DP.count(id)) return DP[id]; 
       for (int i=start; i<=end; i++){
           vector<TreeNode*> l = gt(start, i-1);
           vector<TreeNode*> r = gt(i+1, end);
           
           for (int j = 0; j< l.size(); j++){
               for (int k = 0; k< r.size(); k++){
                   TreeNode * node = new TreeNode(i);
                   node->left = l[j];
                   node->right = r[k];
                   v.push_back(node);
               }
           }           
       }
       return DP[id]=v;
    }
};