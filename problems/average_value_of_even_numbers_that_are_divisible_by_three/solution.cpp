class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum  = 0 , cnt = 0;
        for (auto i : nums)
            if (i%6==0)
                sum +=i,cnt++;
        if (cnt==0) return 0;
        return floor(sum/cnt);
    }
};