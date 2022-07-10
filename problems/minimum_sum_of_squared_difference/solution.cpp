class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int N = nums1.size() ,maxNum= 0;
        vector<int> D(1e5 + 1);
        for (int i=0;i<N; i++){
            auto d  = abs(nums1[i] -nums2[i]);
            D[d]++ ; maxNum = max(maxNum, d);
        }
        
        long long ans = 0, k = k1+k2;  
        
        for (int i=maxNum; i>0; i--){
            if (D[i] == 0)continue;
            k1 = min<long long>(D[i],k);
            D[i] -=k1;
            D[i-1] +=k1;
            k-=k1;
            if (D[i])
                ans += ((long long)i*i) * D[i];
            
        }
        return ans;
    }
	long long minSumSquareDiff1(vector<int>& nums1, vector<int>& nums2, int k1, int k2)  {
		vector<long long> nums(nums1.size());
        long long left = 0, right = 1e5, remain = 0, result = 0;
		for (int i = 0; i < nums1.size(); i++) {
			nums[i] = abs(nums1[i] - nums2[i]);
           
		}
        
        // binary search for diff  which can consume max k <= k1+k2
		while (left < right) {
            
			long long mid = (left + right) / 2, need_k = 0;
            // select a mid (diff) which leads to max k <= k1+k2 
			for (long num : nums) {
				need_k += max<long>(0, num - mid);
			}
            
			if (need_k > k1 + k2) {
				left = mid + 1;
			} else {
				right = mid;
				remain = k1 + k2 - need_k;
			}
		}
        // left =  max diff that can be selected 
		for (long num : nums) {
			result += pow(num < left ? num : (left - min<long>(1, max<long>(0, remain--))), 2);
		}
		return left > 0 ? result : 0;
	}
};