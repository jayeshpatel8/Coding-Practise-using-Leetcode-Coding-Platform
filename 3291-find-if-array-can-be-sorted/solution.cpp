class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int pmax=0 , cmax=0, cmin=cmax;
        int pbits = -1;
        for (int i=0,j=0; i<nums.size(); i++){
            int bits = __builtin_popcount(nums[i]);
            if (nums[i] < pmax) return false;
            if (pbits != bits){      
                if (nums[i] < cmax) return false;          
                pmax = cmax;
                pbits=bits;
                cmax= nums[i];
            }
            else
                cmax=max(cmax, nums[i]);
            
        }
        return true;
    }
};
