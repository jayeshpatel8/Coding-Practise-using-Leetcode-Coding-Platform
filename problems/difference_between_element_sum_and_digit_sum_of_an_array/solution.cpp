class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s1=  accumulate(begin(nums),end(nums),0), s2 =0;
        
        for (auto i : nums)
            for (auto c : to_string(i))
                s2 += c-'0';
        return abs(s1-s2);
    }
};