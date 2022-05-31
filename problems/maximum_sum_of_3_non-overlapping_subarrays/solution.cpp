class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n  = nums.size();
        vector<int> prefix(n+1),left(n),right(n,n-k);
        for (int i=0; i<n; i++)
            prefix[i+1] = prefix[i] + nums[i];
        int sum = 0, msum=0;
        for (int i=k-1; i<n; i++){
            sum = prefix[i+1] - prefix[i-k +1] ;
            if ( sum > msum){
                msum = sum, left[i]  = i-k+1;
            }
            else
                left[i] = left[i-1];
        }
        msum=0;
        for (int i=n-k; i>=0; i--){
            sum = prefix[i+k] - prefix[i] ;
            if ( sum >= msum){
                msum = sum, right[i]  = i;
            }
            else
                right[i] = right[i+1];
        }

        vector<int> ans(3,0);
        for (int i=k; i<=n-2*k; i++){
            int l = left[i-1] , r = right[i+k] , mid = prefix[i+k] - prefix[i];
             sum = mid + prefix[l+k] - prefix[l] + prefix[r+k] - prefix[r];
            if (sum > msum){
                msum = sum;
                ans = {l, i, r};
            }
        }
        return ans;
    }
};