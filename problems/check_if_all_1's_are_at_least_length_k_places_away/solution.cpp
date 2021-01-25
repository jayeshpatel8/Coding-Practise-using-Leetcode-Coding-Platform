class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(k==0)return true;
        int p=-k-1;
        for (int i=0; i<nums.size(); i++){
            if(nums[i]){
                if(i-p>k){
                    p=i;
                }
                else
                    return false;
            }
        }
        return true;
    }
};