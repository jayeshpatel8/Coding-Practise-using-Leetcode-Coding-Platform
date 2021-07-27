class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int closest = nums[0] + nums[1] + nums[2], prev = abs(target-closest);
        //[-4, -1,2,1], target = 1
        for (int i=0; i<nums.size()-2; i++){
            int j=i+1,k = nums.size()-1 , cur = target - (nums[i] + nums[k] + nums[j] );            
            while (j<k){
                if (prev > abs(cur)) 
                    closest = nums[i] + nums[k] + nums[j], prev = abs(cur);
                if (cur > 0)
                    cur = cur + nums[j] - nums[++j] ;                
                else if (cur < 0)
                    cur = cur + nums[k] - nums[--k] ;                
                else 
                    return closest;                
            }
        }
        return closest;
    }
};