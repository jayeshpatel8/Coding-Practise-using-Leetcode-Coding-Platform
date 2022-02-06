class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,N = nums.size();
        if(N<3) return N;
        for (i=2,j=2; i<N; i++ ){
            if (nums[i]>nums[j-2])
                nums[j++]=nums[i];
        }
        return j;
    }
    int removeDuplicates2(vector<int>& nums) {
        int i,j,N;
        for (i=0,j=0,N= nums.size(); i<N; i++ ){
            nums[j++]=nums[i];
            if (i+2<N && nums[i] == nums[i+1] && nums[i+2] == nums[i]){
                nums[j++]=nums[i];
                for (i+=2; i<N && nums[i-1]==nums[i]; i++) ;
                i--;                
            }
        }
        return j;
    }    
};