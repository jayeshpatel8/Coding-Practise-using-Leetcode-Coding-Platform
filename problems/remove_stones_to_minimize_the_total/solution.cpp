class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq (begin(piles), end(piles));
        
        while(k-- && !pq.empty()){
            int high = pq.top() ; pq.pop();
            pq.push(high/2 + (high & 1));            
        }
        int stones=0;
        while(!pq.empty()){
            stones +=pq.top(); pq.pop();
        }
        return stones;
    }
};