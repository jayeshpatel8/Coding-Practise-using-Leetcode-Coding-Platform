

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int len=nums.size();

        if (len < 2) return;
        int i = len -2;
        for ( ; i >=0; i--)
            if (nums[i]<nums[i+1]) break;

        if (i>=0)
        {
            int j;
            for ( j=len-1; j >i; j--)
                if (nums[j]>nums[i]) 
                    break;

            int t=nums[j];
            nums[j] = nums[i];
            nums[i]=t;  
        }     
        i+=1;
        while ( i< --len)
        {
            int t=nums[len];
            nums[len] = nums[i];
            nums[i++]=t;              
        }
    }
};