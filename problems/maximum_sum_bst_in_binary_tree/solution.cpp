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
    int ans = 0;
    int maxSumBST(TreeNode* root) {
        int minv, maxv;
        msum(root,minv,maxv);
        return ans;
    }
    int msum(TreeNode * r , int & minv, int & maxv){
        if (r == 0){
            minv=INT_MAX, maxv=INT_MIN;
            return 0;
        }
        int lsum , rsum, sum = 0, minv2,maxv2;
        lsum = msum(r->left,minv,maxv);
        rsum = msum(r->right,minv2,maxv2);
        if (maxv < r->val && minv2 > r->val) {
            minv = min(minv,r->val);
            maxv = max(maxv2, r->val);
            sum =lsum + r->val +rsum;   
            ans =  max (ans, sum);
        }else{
            maxv = INT_MAX, minv = INT_MIN;
        }
        return sum;
    }
};