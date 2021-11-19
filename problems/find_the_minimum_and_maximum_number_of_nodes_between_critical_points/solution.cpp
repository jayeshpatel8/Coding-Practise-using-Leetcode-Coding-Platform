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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int max_c =0 , min_c = INT_MAX, cnt = -1;
        int prev = head->val,cur = head->next ? head->next->val: 0;
        head= head->next;
        while(head->next){
            int next = head->next->val;
            
            if ((prev < cur && cur > next) || (prev > cur && cur < next) ){           
                if (cnt != -1) 
                    min_c = min(min_c, cnt), max_c += cnt;
                cnt=1;                
            }
            else if (cnt >= 0) 
                cnt++;
            prev = cur; cur= next;
            head= head->next;
        }
        if (min_c == INT_MAX )
            return {-1,-1};
        else
            return { min_c,max_c};
    }
};