class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1, i=0,j=0;
        deque<int> maxq,minq;
        for (; i<nums.size(); i++){
            while (!maxq.empty() && nums[i] > maxq.back()) maxq.pop_back();
            while (!minq.empty() && nums[i] < minq.back()) minq.pop_back();
            maxq.push_back(nums[i]);minq.push_back(nums[i]);
            if (maxq.front() -minq.front() > limit){
                if (nums[j] == maxq.front() ) maxq.pop_front();
                if (nums[j] == minq.front() ) minq.pop_front();
                j++;
            }
            ans= max(ans, i-j+1);
            
        }
        return ans;
    }
    int longestSubarray2(vector<int>& nums, int limit) {
        int ans = 1;
        multiset<int> set;
        for (int i=0,j=0, mi=INT_MAX,ma=INT_MIN; i<nums.size(); i++){
            set.insert(nums[i]);
            while (*rbegin(set) -*begin(set) > limit) set.erase(set.find(nums[j++]));
            ans= max(ans, i-j+1);
            
        }
        return ans;
    }
};