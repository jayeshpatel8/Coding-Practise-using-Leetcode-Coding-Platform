class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& tar) {
        sort(begin(nums), end(nums));
        sort(begin(tar), end(tar));
        long long ans=0;
        for (int i=0,odd=0,even=0; i<nums.size(); i++){
            auto &j =  (nums[i] & 1) ? odd : even;
            while ((nums[i] & 1) != (tar[j] &1)) j++;
            ans += abs(nums[i] -tar[j++])/2;
        }
        return ans/2;
    }
};
// 4,-2,-2