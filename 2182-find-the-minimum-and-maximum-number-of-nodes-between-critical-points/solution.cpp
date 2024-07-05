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
        ListNode *h =  head->next  , *p = head;
        int i=1 ;
        vector<int> cp;

        while (h && h->next){
            auto c= h->val;
            if (( p->val < c && c > h->next->val) ||( p->val > c && c < h->next->val))
                cp.push_back(i);
            i++;
            p=h;
            h=h->next;
        }
        if (cp.size() < 2) return  {-1,-1};
        int m=INT_MAX;
        for (auto i=1; i< cp.size(); i++){
            m = min(m, cp[i]-cp[i-1]);
        }
        for (auto i : cp) cout << i << " ";
        return {m,cp.back()-cp.front()};
    }
};
