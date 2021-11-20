class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0 , N = nums.size(), r = N-1;
        if (N == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[N - 1] != nums[N - 2]) return nums[N - 1];        
        while (l <=r){
            int m = l + (r - l) / 2;
            
            if (m+1<N && nums[m+1] == nums[m]){
                m++;                
            }
            if (m==0) return nums[m];
            else if (nums[m-1]!=nums[m]) return nums[m];
            if (m %2 == 0)
                r = m-1;
            else
                l = m +1;
        }
        return nums[l];
    }
};