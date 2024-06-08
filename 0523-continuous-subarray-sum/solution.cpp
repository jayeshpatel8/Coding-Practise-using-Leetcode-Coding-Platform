class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int N= nums.size();
        if (N<2) return false;           
           unordered_map<int,int> rem= {{0,-1}};
           int r=0;
           for (int i=0 ; i<N; i++){
             r = (r + nums[i]) % k;
            if (rem.find(r) != rem.end()) {
                // ensures that the size of subarray is atleast 2
                if (i - rem[r] > 1) {
                    return 1;
                }
            } else {
                // mark the value of prefixMod with the current index.
                rem[r] = i;
            }
           }
           return false;
    }
};
