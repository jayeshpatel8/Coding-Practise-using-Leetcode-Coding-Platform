class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // E A B C D
        
        int min_e  = INT_MAX ;
        int start=1,end=0, max_e  = INT_MIN;
        for (int i=0, j = nums.size()-1; i<nums.size(); i++,j--){
            if (max_e < nums[i]) max_e = nums[i];
            if (max_e > nums[i]) end  = i;
            
            if (min_e > nums[j]) min_e = nums[j];
            if (min_e < nums[j]) start  = j;  
        }
        return end-start+1;
    }
};