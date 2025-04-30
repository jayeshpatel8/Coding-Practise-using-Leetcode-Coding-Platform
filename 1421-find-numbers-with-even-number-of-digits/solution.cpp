class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for (auto i : nums){
            int cnt=0;
            while(i>0){
                i/=10;
                cnt++;
            }
            ans += cnt % 2 == 0;
        }
        return ans;
    }
};
