class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        //[1,-10,7,13,6,8]
        //1,3,0,6,,6,1
        vector<int> rem(value);
        for (auto i : nums){
            rem[(value + (i%value ))%value]++;
        }

        int ans = 0;
        for (; ans< nums.size(); ans++){
            if (--rem[ans%value] < 0) return ans;
        }
        return ans;
    }
};