class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int f[100002* 2]={};
        int ans = 0;
        for (auto i : nums) f[i]++;
        for (int i=0,k=0;i<200001 && k<nums.size(); i++){
            k += f[i]>0;
            if (f[i] <2) continue;
            int d = f[i]-1;
            f[i+1] +=d;
            ans +=d;

        }
        return ans;
    }   
};
