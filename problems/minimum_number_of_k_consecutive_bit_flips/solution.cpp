class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped=0, ans = 0;
        for (int i =0 , N = nums.size(); i<N; i++){
            if (i>=k){
                if (nums[i-k]>1)
                    flipped--;
            }
            if (flipped%2 == nums[i]){
                if (i+k-1>= N) return -1;
                nums[i]+=2;
                flipped++;
                ans++;
            }
        }
        return ans;
    }
};