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
    
    int minCameraCover(TreeNode* root) {
        int cnt =0;
        if (!root ) return 0;

        if (minc(root, cnt)==1) cnt++;
        return cnt;
    }
    int minc(TreeNode * root, int & cnt)
    {
        if (!root ) return 0;
        int L = minc(root->left,cnt);
        int R = minc(root->right,cnt);
        if (L==1 || R==1) {
            cnt++;
            return -1;
        }        
        
        if (L==-1 || R==-1) return 0;
        else return 1;
    }
};