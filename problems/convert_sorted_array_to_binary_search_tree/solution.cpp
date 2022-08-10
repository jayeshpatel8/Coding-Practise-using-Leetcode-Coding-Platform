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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums,0,nums.size()-1);    
    }
    TreeNode * BST(vector<int>& nums, int i, int j){
        if (i>j) return NULL;
        if (i==j) return new TreeNode(nums[i]); 
        int mid = (i+j+1)/2;
        auto * node  = new TreeNode(nums[mid]);
        
        node->left = BST(nums,i,mid-1);
        node->right = BST(nums,mid+1,j);
        return node;
    }
};