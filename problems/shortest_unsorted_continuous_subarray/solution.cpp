class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minv = INT_MAX, maxv = INT_MIN,f=0;
        for (int i=1 ; i<nums.size(); i++){
            if (nums[i] <  nums[i-1])
                minv =min(minv ,  nums[i]);
        }
        if (minv == INT_MAX) return 0;
        for (int i=nums.size()-2; i >=0 ; i--){
            if (nums[i] >  nums[i+1])
                maxv =max(maxv ,  nums[i]);
        }
        int i=0, j=nums.size()-1;
        for (; i<nums.size(); i++){
            if (minv < nums[i]) break;
        }
        for (; j >=0; j--){
            if (maxv > nums[j]) break;
        }
        return j - i  < 0 ? 0 : j-i +1;
    }
};