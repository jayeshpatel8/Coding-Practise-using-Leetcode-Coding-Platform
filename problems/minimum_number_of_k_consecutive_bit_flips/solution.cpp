class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flipped=0, ans = 0, N = nums.size();
        vector<bool> flip(N);
        for (int i =0 ; i<N; i++){
            if (i>=k){
                if (flip[i-k])
                    flipped--;
            }
            if (flipped%2 == nums[i]){
                if (i+k-1>= N) return -1;
                flip[i]=1;
                flipped++;
                ans++;
            }
        }
        return ans;
    }
};