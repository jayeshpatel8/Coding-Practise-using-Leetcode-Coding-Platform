class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> inc(N,1), ans;
        for (int i=N-2; i>=0; i--)   {
            if (nums[i] <= nums[i+1]) inc[i] = 1 + inc[i+1];
        }
        for (int i=1, c=1;i<N-k;i++){
            if (c >=k && inc[i+1]>=k) ans.push_back(i);
            if (nums[i] <=  nums[i-1]) c += 1;
            else c = 1;            
        }
        return ans;
    }
};