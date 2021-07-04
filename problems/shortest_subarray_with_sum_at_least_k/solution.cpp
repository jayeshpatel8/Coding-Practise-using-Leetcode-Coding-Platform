class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        int len=INT_MAX;
        for (int i=0; i<nums.size(); i++){
            if (i > 0)
                nums[i] +=nums[i-1];
            if (nums[i]>=k) len = min(len,i+1);
            while(!dq.empty() && nums[i] - nums[dq.front()] >= k ){
                len = min(len, i-dq.front());dq.pop_front();
            }            
            while(!dq.empty() && nums[dq.back()]>nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return len==INT_MAX? -1 : len;
    }
};

