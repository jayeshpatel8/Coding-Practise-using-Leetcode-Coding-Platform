class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> f(101), ans(nums.size()-k+1);
        for (int i=0,j1=0; j1<=nums.size()-k; i++){
            int n = nums[i] + 50;
            f[n]++;
            if (i>=k-1){
                int c = 0;
                for (int j=0; j<50; j++){
                    c += f[j];
                    if (c >= x){                        
                        ans[j1]=j-50;
                        break;
                    }
                }
                f[nums[j1++]+50]--;
            }
        }
        return ans;
    }
};