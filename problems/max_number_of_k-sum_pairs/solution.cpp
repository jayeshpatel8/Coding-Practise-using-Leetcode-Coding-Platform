static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res=0,start=0,end=nums.size()-1;
        while (start < end){
            int sum = nums[start] + nums[end];
            if (sum == k){
                res++;start++,end--;
            }
            else if (sum < k) start++;
            else end--;
        }
        return res;
    }
};