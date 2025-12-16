class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        unordered_set<int> st;
        ll ans = 0, sum=0;
        for (int i=0,j=0; i<nums.size(); i++){
            auto n = nums[i];
            if (st.count(n)){
                while ( j<i && (nums[j] != n)){
                    st.erase(nums[j]);                
                    sum -= nums[j++];
                }
                sum -= nums[j++];
            }
            sum += n;
            st.insert(n);

            if (i-j + 1== k ){
                ans=max(ans,sum);
            }
            else if (i - j >= k){
                st.erase(nums[j]);                
                sum-=nums[j++];                
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
