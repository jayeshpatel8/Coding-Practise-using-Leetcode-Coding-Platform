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
        string start ,dst;
        path(root,start,startValue),path(root,dst,destValue);

        int s1 = start.size(),s2=dst.size(), i=0;
        for (; i<s1 && i<s2 && start[i] == dst[i]; i++){
            ;
        }
        
        
        return string(s1-i,'U') + dst.substr(i);
    }
    bool path(TreeNode* root, string &s, int n){
        if (!root) return false;
        if (root->val == n) return (true);
        s+='L';
        if (path(root->left, s,n)) return true;
        s.pop_back();
        s+='R';
        if (path(root->right, s,n)) return true;
        s.pop_back();
        return false;
    }
};