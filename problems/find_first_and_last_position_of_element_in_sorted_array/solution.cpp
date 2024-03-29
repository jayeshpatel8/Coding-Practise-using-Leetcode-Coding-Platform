class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int N =  nums.size();
        if (!N) return {-1,-1};
        auto it = upper_bound(begin(nums), end(nums),target-1);
        if (it ==end(nums) ||  *it != target) return {-1,-1};

        auto it2 = upper_bound(begin(nums), end(nums),target);
        if (it2 == end(nums)) return {(int)(it-begin(nums)), N-1};
        else return {(int)(it-begin(nums)), (int)(it2 - begin(nums)-1)};
    }
};