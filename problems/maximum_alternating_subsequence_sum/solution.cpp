class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // [6,2,1,2,4,5]
        // hill 6 -  valley 1 --  hill 5
        //  6  1   5 OR
        // 6 + 2-1 + 4-2 + 5-4 = 10
        long long ans = nums[0];//  hill
         
        for (int i=1; i<nums.size(); i++){
            ans  += max(0,nums[i]-nums[i-1]);
        }
        return ans;
    }
    // 4 , 2 , 5

};

//  2, 5  7
