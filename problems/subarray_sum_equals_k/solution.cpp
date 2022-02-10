class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> psum={{0,1}};
        int ans = 0, sum = 0;
        sum = 0;
        for (auto i : nums){            
            sum += i;
            if (psum.count(sum - k)) ans +=psum[sum - k];
            ++psum[sum];
        }        
        return ans;
    }
};