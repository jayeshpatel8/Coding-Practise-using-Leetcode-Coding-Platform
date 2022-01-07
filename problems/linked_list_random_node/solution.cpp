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
    ListNode * h;
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        ListNode  *t = h;
        int k=1, cnt=1, ans = 0;
        while (t){
            if (rand() % cnt++ < k) ans = t->val;
            t=t->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */