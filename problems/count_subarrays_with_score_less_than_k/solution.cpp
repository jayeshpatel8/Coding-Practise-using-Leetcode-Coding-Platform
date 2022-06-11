class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int N = nums.size();
        long long sum=0, ans = 0;
        for (int i=0,j=0; i<N; i++){
            sum +=nums[i];
            while (sum * (i-j + 1) >= k) {
                sum -=nums[j];
                j++;
            }
            ans += i - j +1;
        }
        return ans;
    }
};