class Solution {
public:
    int numberOfSubarrays2(vector<int>& nums, int k) {
        int  ans = 0;
        for (int i=0,j=0, odd=0, prefix=0; i<nums.size(); i++){
            auto n = nums[i];
            if (n & 1){
                if (++odd >=k){
                    prefix = 0;
                    while (nums[j]%2==0) prefix++,j++;
                    j++;
                    odd--;
                    ans  +=  1 + prefix;
                }
            }
            else{
                if (odd == k)
                    ans  +=  1 + prefix;
            }
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int  ans = 0;
        for (int i=0,j=0, odd=0, prefix=0; i<nums.size(); i++){
            auto n = nums[i];
            odd += (n&1) == 1;
            if (odd > k) prefix=0;
            while (odd>k) odd -= (nums[j++]&1) == 1;
            while (odd== k && nums[j]%2 == 0) prefix++,j++;
            if (odd == k)
                ans += 1 +prefix;
        }
        return ans;
    }

};