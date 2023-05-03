class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        vector<int> f(1001);
        for (auto i  : nums) f[i]++;

        int ans =0, a=0, N= nums.size();;
        for (auto b : f){
            if (!b) continue;
            int c = N -a - b;
            ans += a * b * c;
            a +=b;
        }
        return ans;
    }
    int unequalTriplets2(vector<int>& nums) {
        vector<int> f(1001);
        for (auto i : nums) f[i]++;
        int ans = 0, N= nums.size();
        for (auto i =0; i<N-2; i++) {            
            for (auto j =i+1; j<N-1; j++) {
                if (nums[i] == nums[j]) continue;
                for (auto k =j+1; k<N; k++) {
                    if (nums[i] == nums[k]) continue;
                    if (nums[k] == nums[j]) continue;
                    ans++;                    
                }
            }
        }
        
        return ans;
    }
};