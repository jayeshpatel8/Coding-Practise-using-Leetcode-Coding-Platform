class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (auto i : nums) m[i] = __builtin_popcount(i);

        int f=1;
        while (f){
            f=0;
            for (int i=1; i<n; i++){
                int a = nums[i-1], b =  nums[i];
                if (a<=b) continue;
                if (m[a] != m[b]) return false;
                swap(nums[i-1],nums[i]);
                f=1;
            }
        }
        return true;
    }
};
