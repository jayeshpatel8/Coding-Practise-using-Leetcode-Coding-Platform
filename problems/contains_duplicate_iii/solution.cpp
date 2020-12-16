class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k==0) return false;
        unordered_map<int,int> buckets;
        vector<int> bucket(nums.size());
        for (int i=0; i<nums.size(); i++){
            bucket[i] = nums[i] / ((long)t + 1);
            
            if (nums[i] < 0)  bucket[i]--;
            
            if (buckets.find(bucket[i]) != buckets.end()) return true;
                        
            if (buckets.find(bucket[i]+1) != buckets.end()
                && (long)buckets[bucket[i]+1] - nums[i] <= t) return true;
            if (buckets.find(bucket[i]-1) != buckets.end()
                && (long)nums[i]-buckets[bucket[i]-1] <= t) return true;
            buckets[bucket[i]]= nums[i];
            if (buckets.size() > k )
                buckets.erase(bucket[i-k]);            
        }
        return false;
    }
    
};