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
        ListNode* h = head ;
        if (!h) return nullptr;;
        int len=0;
        while (h) h=h->next, len++;

        return sortedArrToBST2(head,0,len-1);
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