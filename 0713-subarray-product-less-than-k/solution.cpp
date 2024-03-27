class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1) return 0;
        int i=0,j=0 , p = 1 ,ans = 0;
        for (; i<nums.size();  i++){
            p *= nums[i];

            while (p>=k)
                p/=nums[j++];   
            
            ans += i - j + 1;
        }

        return ans;
    }  
};
