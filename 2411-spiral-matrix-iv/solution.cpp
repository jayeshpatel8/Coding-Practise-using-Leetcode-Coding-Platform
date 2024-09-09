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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans (m, vector<int>(n,-1));
        int r1=0, r2= m-1, c1=0,c2=n-1;
        auto h = head;
        int tot= m * n , cnt = 0;
        for (int r1=0,r2=m-1, c1=0,c2=n-1; r1<=r2 && c1 <= c2 && r1<m &&c1<n && r2>=0 && c2>=0; r1++,r2--,c1++,c2--){
            for (int i=r1,j=c1; j<=c2 ; j++){
                if (!h) return ans;
                ans[i][j] = h->val;
                h=h->next;
            }

            for (int i=r1+1,j=c2; i<=r2 ; i++){
                if (!h) return ans;
                ans[i][j] = h->val;
                h=h->next;
            }

            for (int i=r2,j=c2-1; j>=c1 ; j--){
                if (!h) return ans;
                ans[i][j] = h->val;
                h=h->next;
            }

            for (int i=r2-1,j=c1; i>r1 ; i--){
                if (!h) return ans;
                ans[i][j] = h->val;
                h=h->next;

            }
        }
        return ans;
    }    
};
