class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int i=0;
        
        while(i<k) pq.push(nums[i++]);
        int top = pq.top();
        for (;i<nums.size();i++){
            if (nums[i]>top)
            {
                pq.pop();
                pq.push(nums[i]);
                top = pq.top();
            }
        }
        return top;
    }
};