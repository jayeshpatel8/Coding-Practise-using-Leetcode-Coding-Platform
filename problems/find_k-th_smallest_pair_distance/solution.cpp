class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int l = 0, r = nums[nums.size()-1]-nums[0] ;
        while (l<r){
            int m = l + ( r - l ) / 2, cnt = 0;
            
            for (int i=0,j=0; j<nums.size(); j++){
                while(nums[j] -nums[i] > m) i++;
                cnt += j-i;
            }
            if (cnt>=k) r = m;
            else l = m+1;
        }
        return l;
    }
};