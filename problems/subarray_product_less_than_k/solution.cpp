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
    int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
        int i=0,j=0 , p = 1 ,ans = 0;
        for (; i<nums.size();  i++){
            p *= nums[i];
            if (p < k){
                ans += i - j + 1;
            }            
            else{
                while (j<=i && p>=k)
                    p/=nums[j++];                            
                if (j<=i)
                    ans += i - j + 1;
            }
        }

        return ans;
    }
};