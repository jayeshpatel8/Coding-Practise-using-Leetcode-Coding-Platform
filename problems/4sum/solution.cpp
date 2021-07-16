class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int N = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<N-3; i++ ){
            if (i>0 && nums[i-1]==nums[i]) continue;
            for (int j = i+1; j<N-2; j++){
                if (j-i>1 && nums[j-1]==nums[j]) continue;
                int start=j+1, end=N-1;
                long sum = target - nums[i]-nums[j];
                while(start<end){

                    long n = nums[start] + nums[end];
                    if ( n == sum)
                    {
                        ans.push_back({nums[i],nums[j],nums[start++],nums[end--]});
                        while (start<end && nums[start] == nums[start-1] )
                            start++;
                        while (start<end && nums[end] == nums[end+1]  ) 
                            end--;                                           
                    }
                    else if (n < sum)start++;
                    else end--;

                }
            }
        }
        return ans;
    }
};