class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int f[101]={};
        for (int i=nums.size()-1; i>=0; i--){
            if (f[nums[i]]){
                int j = i+1;
                return j/3 + (j%3 != 0);
            }
            f[nums[i]]=1;
        }
        return 0;
    }
};
