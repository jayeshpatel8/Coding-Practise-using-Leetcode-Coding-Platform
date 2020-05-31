/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return 0;
       // vector<int> arr;
        int len=0;
        ListNode *cur=head;
        while (head ){
            //arr.push_back(head->val); 
            head=head->next;
            len++;
        }
        //return sortedArrToBST1(arr, 0,arr.size()-1);
        return sortedArrToBST2(cur, 0,len-1);
    }
    TreeNode* sortedArrToBST1(vector<int>& arr,int l, int r){
        if (l<=r){
            int m = l + (r-l)/2;
            TreeNode * root = new TreeNode(arr[m]);
            root->left = sortedArrToBST1(arr, l,m-1);
            root->right = sortedArrToBST1(arr, m+1, r);
            return root;
        }
        return 0;
    }
    TreeNode* sortedArrToBST2(ListNode* &head,int l, int r){
        if (l<=r){
            int m = l + (r-l)/2;
             TreeNode * root = new TreeNode;
            root->left = sortedArrToBST2(head, l,m-1);
            root->val = head->val;
            head=head->next;
            root->right = sortedArrToBST2(head, m+1, r);
            return root;
        }
        return 0;
    }
    
};