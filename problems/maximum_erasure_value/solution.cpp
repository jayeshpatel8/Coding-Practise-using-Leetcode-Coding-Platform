class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //[4,2,4,5,6]
        
        unordered_map<int,int> m;
        int cur=0, msum=INT_MIN,start=0;
        for (int i=0;  i< nums.size(); i++){
            
            if (m.find(nums[i]) != m.end()){
                int t = m[nums[i]];
                
                while (start <=t){
                    cur -=nums[start++];
                }
                
            }
            m[nums[i]]=i;
            cur += nums[i];
            msum = max (msum,cur);
        }
        return msum;
    }
};