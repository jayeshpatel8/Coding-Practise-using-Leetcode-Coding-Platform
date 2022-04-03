class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        for  (int n=nums.size(),i=n-1; i>0; i--){
            
            if (nums[i-1] < nums[i] ){ // find first decreasing number i.e. nums[i-1]
                int j=nums[i-1] , k = i;
                while ( k<n && j < nums[k]) k++; // find next higher smallest number than nums[i-1]
                nums[i-1]=nums[k-1]; nums[k-1]=j;
                reverse(begin(nums)+i,end(nums));        
                return;
            }                        
        }        
        reverse(begin(nums),end(nums)); // if nums[] is in descending order then reverse it
    }
};