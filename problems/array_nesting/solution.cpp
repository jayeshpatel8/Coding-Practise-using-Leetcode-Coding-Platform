class Solution {
public:
 
    int arrayNesting(vector<int>& nums) {
        int ans=1;
        for ( int i=0; i< nums.size(); i++){
            int j = i, cnt = 0;
            while (nums[j] != j){                
                ++cnt; 
                int t =nums[j]; 
                nums[j] = j;
                j=t;
            }
            ans= max(ans,cnt);
        }
        return ans;
    }
};