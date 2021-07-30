class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int sum=0,l=-1, ans=0;
        unordered_map<int,int> M;
        M[0]=-1;
        for (int r = 0; r <nums.size(); r++){
            sum +=nums[r];
            int diff = sum - target;
            if (M.find(diff) != M.end()  && M[diff] >= l){
                ans++;
                l = r;
            }
            M[sum] = r;
        }
        return ans;
    }
};