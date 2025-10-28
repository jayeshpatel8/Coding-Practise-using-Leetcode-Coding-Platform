class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int p=nums[0], ans= 0;
        vector<int> psum(nums.size()+1);
        for ( auto i =0; i<nums.size(); i++){
            psum[i+1] =psum[i]+nums[i] ;
        }
        for (auto i=0; i<nums.size(); i++){
            if (nums[i] == 0 )
                if (2 * psum[i+1] == psum.back())
                    ans+=2;
                else if ( abs(psum.back() - 2 * psum[i+1])==1)
                    ans++;
        }
        return ans;
    }
};
