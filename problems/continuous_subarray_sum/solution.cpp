class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N= nums.size();
        if (N<2) return false;
        if (k == 1 ) return true;
        {
            int prev=1;
            for (auto i : nums){
                if (prev + i == 0) return true;
                prev=i;
            }
            if (k==0) return false;
        }
        
        unordered_map<int,int> remainder;
        int sum=nums[0];
        for (int i=1; i<N; i++){
            sum +=nums[i];
            int r = sum %k;
            if (!r || remainder.count(r)) return true;
            else remainder[(sum-nums[i])%k]=1;
        }
        return false;
    }
};