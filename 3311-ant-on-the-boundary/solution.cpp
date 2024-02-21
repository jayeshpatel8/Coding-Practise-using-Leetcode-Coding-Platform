class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int c = 0, ans =  0;
        for (auto i : nums){
            c += i;
            if (c==0) ans++;
        }   
        return ans;
    }
};
