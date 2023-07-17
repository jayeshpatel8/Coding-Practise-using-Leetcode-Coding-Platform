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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getlen(l1), len2 = getlen(l2);
        auto [n,c] =  sum(l1,l2,len1,len2);
        if (c) {
            ListNode * r = new ListNode(1,n);
            return r;
        }
        return n;
    }
    int getlen(ListNode * root){
        int l=0;
        while (root) root=root->next,l++;
        return l;
    }
    pair<ListNode *,int>  sum(ListNode * r1,ListNode * r2, int l1, int l2){
        if (l1 != l2){
            ListNode * r;
            if (l1 > l2)  {
                r= r1;
                auto [n,c] = sum(r->next,r2,l1-1,l2);
                r->next = n;
                r->val+=c;
            }
            else{
                r= r2;
                auto [n,c] = sum(r1,r->next,l1,l2-1);
                r->next = n;
                r->val+=c;
            }
            
            if (r->val > 9){
                r->val %=10;
                return {r,1};
            }
            return {r,0};
        }
        else{
            if (l1==0) return {nullptr, 0};
            auto [n,c] = sum(r1->next,r2->next,l1-1,l2-1);
            ListNode * r = new ListNode;
            r->val = r1->val + r2->val + c;
            r->next= n;
            if (r->val > 9){
                r->val %=10;
                return {r,1};
            }
            else return {r,0};
        }
    }
};