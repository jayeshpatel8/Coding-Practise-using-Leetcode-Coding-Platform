class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> psum(nums.size()+1),ans;
        for (int i=0; i<nums.size(); i++)
            psum[i+1] = psum[i]+ nums[i];
        for (int i=0; i<nums.size(); i++){
            int sum =  0;
            if (i>0) sum += psum[i];
            if (i+1< nums.size()) sum = abs(sum - (psum[nums.size()] - psum[i+1] ));
            ans.push_back(sum);
        }
        return ans;
    }
};