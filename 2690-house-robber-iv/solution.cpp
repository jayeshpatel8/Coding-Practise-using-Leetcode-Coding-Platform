class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l=1, r=1e9;
        while (l<r){
            int mid  = l+(r-l)/2;
            int i=0, cnt=0;
            for (; i<nums.size() && cnt < k; i++){
                if (nums[i] <=mid){
                    cnt++;
                    i++;
                }
            }
            if (cnt==k)
                r = mid;
            else l = mid +1;
        }
        return r;
    }
};
