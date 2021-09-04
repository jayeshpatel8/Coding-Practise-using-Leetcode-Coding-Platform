class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int psum[102]={};
        for ( int i=0; i<nums.size(); i++)
            psum[i+1] = psum[i] + nums[i];
        psum[nums.size()+1] = psum[nums.size()];
        {
            if (psum[nums.size()]-psum[1]==0) return 0;
        }        
        for ( int i=1; i<nums.size(); i++){
        
            if (psum[i]==psum[nums.size()]-psum[i+1]) return i;
        
        }
      
        return -1;
    }
};