class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k==0) return nums1==nums2 ? 0 : -1;
        for (int i=0; i<nums1.size(); i++){
            nums1[i] -= nums2[i];
        }
        
        long cnt = 0, ans = 0;
        for (int i=0; i<nums1.size(); i++){
            if (nums1[i] < 0){
                cnt += nums1[i]/k;
                if (nums1[i]%k) return -1;
            }
            else if (nums1[i] > 0 ){
                 ans += nums1[i]/k;
                if (nums1[i]%k) return -1;
            }
        }
        return ans == abs(cnt) ?  ans : -1;
    }
};