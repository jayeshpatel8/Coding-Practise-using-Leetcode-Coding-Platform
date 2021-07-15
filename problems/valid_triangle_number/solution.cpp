class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0;
        for (int i = nums.size()-1; i>=2; i--){
            int last = nums[i] , l =0, r = i-1;;
            while (  l<r ){
                if (nums[l]+nums[r] > last){
                    ans += r-l;
                    r--;
                }
                else
                    l++;
            }
        }
        return ans;
    }
};