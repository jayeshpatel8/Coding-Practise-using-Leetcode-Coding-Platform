class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = INT_MAX,res = (nums[0] + nums[1] + nums[2]), N = nums.size();
        sort(begin(nums),end(nums));
        for (int i=0; i< N ; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            auto second = i + 1 ,third = N-1;
            while (second < third){
                auto sum = nums[i] + nums[second] + nums[third];
                if (sum == target) return target;
                if(abs(target -sum) <abs(target - res)){
                    res = sum;
                }
                if (sum  > target) third--;
                else second++;
            }
        }
        return res;
    }
};