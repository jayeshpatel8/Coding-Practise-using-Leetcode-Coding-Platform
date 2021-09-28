class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int even = 0, odd = 1;
        while(even < nums.size() ){
            if ( nums[even] % 2 ){                    
                    while(nums[odd] % 2) odd+=2;
                    swap(nums[odd], nums[even]);
                odd+=2;
            }
            even+=2;
        }
        return nums;
    }
};