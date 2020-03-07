
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int miin,maax,out;        
    miin=maax=out=nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i] < 0)
                swap(miin,maax);
            miin=min(nums[i],nums[i]*miin);
            maax=max(nums[i],nums[i]*maax);
            out = max(out,maax);
        }
    
        return out;
    }
};