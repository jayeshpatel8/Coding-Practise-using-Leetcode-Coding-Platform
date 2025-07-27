class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0,N = nums.size();

        for (int i=1; i< N-1; i++){
            int l = i-1, r= i+1;
            while (l>=0 && nums[l] == nums[i]) l--;
            if (l < 0) continue;
            while (r <N && nums[r] == nums[i]) r++;
            if (r==N) continue;
            if (nums[i] > nums[l] && nums[i] > nums[r]) ans++;
            if (nums[i] < nums[l] && nums[i] < nums[r]) ans++;
            if ( r-i > 1) i +=r-i-1;
        }
        return ans;
    }
};
